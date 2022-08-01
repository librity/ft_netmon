/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 17:04:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	*find_worker_return_writer(void)
{
	return (find_status_or_exit(workers, worker_returns, WORKER_THREAD_COUNT));
}

#define WORKER_EXIT_FMT "Cleanly exiting worker thread %lu: \
thread cancelation signal activated."

void	exit_worker_cleanly(void *_arg)
{
	int	*return_writer;

	return_writer = find_worker_return_writer();
	*return_writer = THREAD_EXIT_OK;
	tdebug(WORKER_EXIT_FMT, pthread_self());
	pthread_mutex_unlock(&queue_mutex);
}

void	init_worker(void)
{
	int	*return_writer;

	disable_cancellation();
	return_writer = find_worker_return_writer();
	*return_writer = THREAD_RUNNING;
	enable_cancellation();
}

void	*run_worker(void *_args)
{
	t_task	task;

	init_worker();
	pthread_cleanup_push(&exit_worker_cleanly, NULL);
	while (true)
	{
		pthread_mutex_lock(&queue_mutex);
		wait_for_task();
		task = dequeue_task();
		pthread_mutex_unlock(&queue_mutex);
		execute_task(&task);
	}
	pthread_cleanup_pop(NULL);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define WORKER_EXIT_FMT "Cleanly exiting worker thread %lu: \
thread cancelation signal activated."

static void	exit_worker_cleanly(void *_arg)
{
	(void)_arg;
	set_self_status(THREAD_EXIT_OK);
	tdebug(WORKER_EXIT_FMT, pthread_self());
	pthread_mutex_unlock(queue_mutex());
}

static void	init_worker(void)
{
	disable_cancellation();
	set_self_status(THREAD_RUNNING);
	enable_cancellation();
}

void	*run_worker(void *_arg)
{
	t_target	*target;

	(void)_arg;
	init_worker();
	pthread_cleanup_push(&exit_worker_cleanly, NULL);
	while (true)
	{
		target = dequeue_safely();
		handle_request(target);
	}
	pthread_cleanup_pop(NULL);
	return (NULL);
}

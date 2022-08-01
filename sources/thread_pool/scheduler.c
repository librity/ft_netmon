/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 17:05:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	*find_scheduler_return_writer(void)
{
	return (find_status_or_exit(schedulers, scheduler_returns,
			SCHEDULER_THREAD_COUNT));
}

#define SCHEDULER_EXIT_FMT "Cleanly exiting scheduler thread %lu: \
thread cancelation signal activated."

void	exit_scheduler_cleanly(void *_arg)
{
	int	*return_writer;

	return_writer = find_scheduler_return_writer();
	*return_writer = THREAD_EXIT_OK;
	tdebug(SCHEDULER_EXIT_FMT, pthread_self());
}

void	init_scheduler(void)
{
	int	*return_writer;

	disable_cancellation();
	return_writer = find_scheduler_return_writer();
	*return_writer = THREAD_RUNNING;
	enable_cancellation();
}

void	*run_scheduler(void *_args)
{
	init_scheduler();
	pthread_cleanup_push(&exit_scheduler_cleanly, NULL);
	while (true)
	{
		enqueue_task(new_task());
		sleep(SCHEDULER_DELAY_SECONDS);
	}
	pthread_cleanup_pop(NULL);
	return (NULL);
}

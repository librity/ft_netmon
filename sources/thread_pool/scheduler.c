/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:43:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define SCHEDULER_EXIT_FMT "Cleanly exiting scheduler thread %lu: \
thread cancelation signal activated."

static void	exit_scheduler_cleanly(void *_arg)
{
	(void)_arg;
	set_self_status(THREAD_EXIT_OK);
	tdebug(SCHEDULER_EXIT_FMT, pthread_self());
}

static void	init_scheduler(void)
{
	disable_cancellation();
	set_self_status(THREAD_RUNNING);
	enable_cancellation();
}

void	*run_scheduler(void *target_vp)
{
	t_target	*target;

	init_scheduler();
	pthread_cleanup_push(&exit_scheduler_cleanly, NULL);
	target = (t_target *)target_vp;
	while (true)
	{
		enqueue_safely(target);
		sleep(target->frequency);
	}
	pthread_cleanup_pop(NULL);
	return (NULL);
}

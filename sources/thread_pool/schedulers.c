/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedulers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 17:03:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define SPAWN_SCHEDULER_FMT "Created scheduler thread with id %lu."

void	spawn_schedulers(void)
{
	spawn_threads(schedulers, &run_scheduler, SCHEDULER_THREAD_COUNT,
		SPAWN_SCHEDULER_FMT);
}

#define CANCEL_SCHEDULER_FMT "Sending cancel signal to scheduler thread %lu."

void	cancel_schedulers(void)
{
	cancel_threads(schedulers, SCHEDULER_THREAD_COUNT, CANCEL_SCHEDULER_FMT);
}

#define JOIN_SCHEDULER_FMT "Joined scheduler thread %lu with return status %d."

void	join_schedulers(void)
{
	join_threads(schedulers, scheduler_returns, SCHEDULER_THREAD_COUNT,
		JOIN_SCHEDULER_FMT);
}

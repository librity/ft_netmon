/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 17:02:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define SPAWN_WORKER_FMT "Created worker thread with id %lu.\n"

void	spawn_workers(void)
{
	spawn_threads(workers, &run_worker, WORKER_THREAD_COUNT, SPAWN_WORKER_FMT);
}

#define CANCEL_WORKER_FMT "Sending cancel signal to worker thread %lu.\n"

void	cancel_workers(void)
{
	cancel_threads(workers, WORKER_THREAD_COUNT, CANCEL_WORKER_FMT);
}

#define JOIN_WORKER_FMT "Joined worker thread %lu with return status %d.\n"

void	join_workers(void)
{
	join_threads(workers, worker_returns, WORKER_THREAD_COUNT, JOIN_WORKER_FMT);
}

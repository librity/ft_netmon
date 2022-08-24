/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define CREATE_MSG "Creating worker threads."

void	create_workers(void)
{
	tdebug(CREATE_MSG);
	create_threads(workers(), &run_worker, NULL, workers_count());
}

#define CANCEL_MSG "Canceling worker threads."

void	cancel_workers(void)
{
	tdebug(CANCEL_MSG);
	cancel_threads(workers());
}

#define JOIN_MSG "Joining worker threads."

void	join_workers(void)
{
	tdebug(JOIN_MSG);
	join_threads(workers());
}

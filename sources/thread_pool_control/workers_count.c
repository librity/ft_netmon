/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workers_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 15:11:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	workers_count(void)
{
	return (tpc()->workers_count);
}

void	set_workers_count(int new_count)
{
	if (new_count < 1)
		die(SET_WORKER_COUNT_ERR);
	if (new_count > MAX_WORKER_THREADS)
		die(SET_WORKER_COUNT_ERR);
	tpc()->workers_count = new_count;
}

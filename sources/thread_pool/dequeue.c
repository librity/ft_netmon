/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	wait_for_request(void)
{
	while (request_count() == 0)
		pthread_cond_wait(queue_cond(), queue_mutex());
}

t_target	*dequeue_safely(void)
{
	t_target	*target;

	pthread_mutex_lock(queue_mutex());
	wait_for_request();
	target = dequeue_request();
	pthread_mutex_unlock(queue_mutex());
	return (target);
}

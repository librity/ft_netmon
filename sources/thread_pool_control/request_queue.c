/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:15:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static t_target	**request_queue(void)
{
	return (tpc()->request_queue);
}

void	enqueue_request(t_target *request)
{
	if (request_count() >= REQUEST_QUEUE_SIZE)
		die(REQUEST_QUEUE_OVERFLOW_ERR);
	request_queue()[request_count()] = request;
	increase_request_count();
}

t_target	*dequeue_request(void)
{
	t_target	*request;
	int			i;

	if (request_count() <= 0)
		die(REQUEST_QUEUE_UNDERFLOW_ERR);
	request = request_queue()[0];
	i = 0;
	while (i < request_count() - 1)
	{
		request_queue()[i] = request_queue()[i + 1];
		i++;
	}
	decrease_request_count();
	return (request);
}

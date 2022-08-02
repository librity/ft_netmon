/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:24:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define CANCEL_MSG "Sent cancelation signal to thread %lu."

void	cancel_threads(t_dlist **threads)
{
	t_dlist	*node;
	int		result;

	node = *threads;
	while (node != NULL)
	{
		result = pthread_cancel(nget_thread_id(node));
		if (result != 0)
			die(THRD_CANCEL_ERR);
		tdebug(CANCEL_MSG, nget_thread_id(node));
		node = node->next;
	}
}

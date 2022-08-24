/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define CANCEL_MSG "\tSent cancelation signal to thread %lu."
#define CANCEL_COUNT_MSG "Total cancellation signals sent: %d."

void	cancel_threads(t_dlist **threads)
{
	t_dlist	*node;
	int		result;
	int		count;

	node = *threads;
	count = 0;
	while (node != NULL)
	{
		result = pthread_cancel(nget_thread_id(node));
		if (result != 0)
			die(THRD_CANCEL_ERR);
		tdebug(CANCEL_MSG, nget_thread_id(node));
		count++;
		node = node->next;
	}
	tdebug(CANCEL_COUNT_MSG, count);
}

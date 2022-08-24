/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define JOIN_MSG "\tJoined thread %lu with return status %d."
#define JOIN_COUNT_MSG "Total threads joined: %d."

void	join_threads(t_dlist **threads)
{
	t_dlist	*node;
	int		result;
	int		count;

	node = *threads;
	count = 0;
	while (node != NULL)
	{
		result = pthread_join(nget_thread_id(node), NULL);
		if (result != 0)
			die(THRD_JOIN_ERR);
		tdebug(JOIN_MSG, nget_thread_id(node), nget_thread_status(node));
		count++;
		node = node->next;
	}
	tdebug(JOIN_COUNT_MSG, count);
}

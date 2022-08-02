/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:27:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define JOIN_MSG "Joined thread %lu with return status %d."

void	join_threads(t_dlist **threads)
{
	t_dlist	*node;
	int		result;

	node = *threads;
	while (node != NULL)
	{
		result = pthread_join(nget_thread_id(node), NULL);
		if (result != 0)
			die(THRD_JOIN_ERR);
		tdebug(JOIN_MSG, nget_thread_id(node), nget_thread_status(node));
		node = node->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

t_thread	*find_thread_in_index(t_dlist **threads, pthread_t id)
{
	t_dlist		*node;

	node = *threads;
	while (node != NULL)
	{
		if (id == nget_thread_id(node))
			return (nget_thread(node));
		node = node->next;
	}
	return (NULL);
}

t_thread	*find_thread(pthread_t id)
{
	t_thread	*worker;
	t_thread	*scheduler;

	worker = find_thread_in_index(workers(), id);
	scheduler = find_thread_in_index(schedulers(), id);
	if (worker != NULL && scheduler != NULL)
		die(THRD_DUPLICATE_ERR);
	if (worker != NULL)
		return (worker);
	if (scheduler != NULL)
		return (scheduler);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nget.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

t_thread	*nget_thread(t_dlist *node)
{
	return ((t_thread *)(node->content));
}

pthread_t	nget_thread_id(t_dlist *node)
{
	t_thread	*thread;

	thread = nget_thread(node);
	return (thread->id);
}

t_tstatus	nget_thread_status(t_dlist *node)
{
	t_thread	*thread;

	thread = nget_thread(node);
	return (thread->status);
}

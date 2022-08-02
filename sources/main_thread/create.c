/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:23:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	initialize_n_threads(t_dlist **threads, int n)
{
	int	expected;

	expected = n;
	while (n--)
		add_thread(threads);
	if (ft_dlstsize(*threads) != expected)
		die(INIT_THREADS_ERR);
}

#define CREATE_MSG "Created thread with id %lu."

void	nspawn_thread(t_dlist *node, t_troutine routine, void *thread_arg)
{
	t_thread	*thread;
	int			result;

	thread = nget_thread(node);
	result = pthread_create(&thread->id, NULL, routine, thread_arg);
	if (result != 0)
		die(THRD_SPAWN_ERR);
	tdebug(CREATE_MSG, thread->id);
}

void	spawn_threads(t_dlist **threads, t_troutine routine, void *thread_arg)
{
	t_dlist		*node;

	node = *threads;
	while (node != NULL)
	{
		nspawn_thread(node, routine, thread_arg);
		node = node->next;
	}
}

void	create_threads(t_dlist **threads, t_troutine routine, void *thread_arg,
		int thread_count)
{
	initialize_n_threads(threads, thread_count);
	spawn_threads(threads, routine, thread_arg);
}

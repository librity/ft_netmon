/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 13:08:39 by lpaulo-m         ###   ########.fr       */
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

#define SPAWN_MSG "\tCreated thread with id %lu."

void	nspawn_thread(t_dlist *node, t_troutine routine, void *thread_arg)
{
	t_thread	*thread;
	int			result;

	thread = nget_thread(node);
	result = pthread_create(&thread->id, NULL, routine, thread_arg);
	if (result != 0)
		die(THRD_SPAWN_ERR);
	tdebug(SPAWN_MSG, thread->id);
}

#define SPAWN_COUNT_MSG "Total threads spawned: %d."

void	spawn_threads(t_dlist **threads, t_troutine routine, void *thread_arg)
{
	t_dlist	*node;
	int		count;

	node = *threads;
	count = 0;
	while (node != NULL)
	{
		nspawn_thread(node, routine, thread_arg);
		count++;
		node = node->next;
	}
	tdebug(SPAWN_COUNT_MSG, count);
}

void	create_threads(t_dlist **threads, t_troutine routine, void *thread_arg,
		int thread_count)
{
	initialize_n_threads(threads, thread_count);
	spawn_threads(threads, routine, thread_arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:51:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	init(void)
{
	pthread_mutex_init(&queue_mutex, NULL);
	pthread_cond_init(&queue_cond, NULL);
}

void	cleanup(void)
{
	pthread_mutex_destroy(&queue_mutex);
	pthread_cond_destroy(&queue_cond);
}

int	main(int arc, char *argv[])
{
	init();
	spawn_workers();
	spawn_schedulers();

	tdebug("Cancelling all threads.");
	cancel_schedulers();
	cancel_workers();

	join_schedulers();
	join_workers();
	cleanup();
	return (EXIT_SUCCESS);
}

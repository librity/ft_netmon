/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:50:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	spawn_threads(pthread_t threads[],
		t_troutine routine,
		int thread_count,
		char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_create(&threads[i], NULL, routine, NULL);
		if (result != 0)
			die(THRD_SPAWN_ERR);
		tdebug(fmt, threads[i]);
		i++;
	}
}

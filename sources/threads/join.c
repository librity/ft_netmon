/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:50:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	join_threads(pthread_t threads[],
				int returns[],
				int thread_count,
				char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_join(threads[i], NULL);
		if (result != 0)
			die(THRD_JOIN_ERR);
		tdebug(fmt, threads[i], returns[i]);
		i++;
	}
}

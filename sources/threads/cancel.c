/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:50:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	cancel_threads(pthread_t threads[], int thread_count, char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_cancel(threads[i]);
		if (result != 0)
			die(THRD_CANCEL_ERR);
		tdebug(fmt, threads[i]);
		i++;
	}
}

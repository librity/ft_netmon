/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:22:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	*find_thread_status(pthread_t threads[],
						int returns[],
						int thread_count)
{
	pthread_t	id;
	int			i;

	id = pthread_self();
	i = 0;
	while (i < thread_count)
	{
		if (id == threads[i])
			return (returns + i);
		i++;
	}
	return (NULL);
}

int	*find_status_or_exit(pthread_t threads[],
							int returns[],
							int thread_count)
{
	int	*status;

	status = find_thread_status(threads, returns, thread_count);
	if (status == NULL)
		tdie(THRD_FIND_STATUS_ERR);
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 13:49:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	initialize_mutex(t_tmutex *mutex)
{
	int	result;

	result = pthread_mutex_init(mutex, NULL);
	if (result != 0)
		die(THRD_MUTEX_INIT_ERR);
}

void	destroy_mutex(t_tmutex *mutex)
{
	int	result;

	pthread_mutex_unlock(mutex);
	result = pthread_mutex_destroy(mutex);
	if (result == EBUSY)
		return (print_warning(BUSY_MUTEX_WARN));
	if (result != 0)
		die(THRD_MUTEX_DESTROY_ERR);
}

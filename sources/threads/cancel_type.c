/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:12:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	switch_deffered(void)
{
	int	set_result;

	set_result = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if (set_result != 0)
		die(THRD_SWITCH_DEFFERED_ERR);
}

void	switch_async(void)
{
	int	set_result;

	set_result = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	if (set_result != 0)
		die(THRD_SWITCH_ASYNC_ERR);
}

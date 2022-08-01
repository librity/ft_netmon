/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:11:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	disable_cancellation(void)
{
	int	set_result;

	set_result = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (set_result != 0)
		tdie(THRD_DISABLE_CANCEL_ERR);
}

void	enable_cancellation(void)
{
	int	set_result;

	set_result = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (set_result != 0)
		tdie(THRD_ENABLE_CANCEL_ERR);
}

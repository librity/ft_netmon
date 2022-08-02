/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 11:55:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	initialize_cond(t_tcond *cond)
{
	int	result;

	result = pthread_cond_init(cond, NULL);
	if (result != 0)
		die(THRD_COND_INIT_ERR);
}

void	destroy_cond(t_tcond *cond)
{
	int	result;

	result = pthread_cond_destroy(cond);
	if (result != 0)
		die(THRD_COND_DESTROY_ERR);
}

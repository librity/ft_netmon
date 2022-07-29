/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 22:50:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	close_or_die(int close_me)
{
	if (close_me == CLOSED_FD)
		die(FD_DOUBLE_CLOSE_ERR);
	close_me = close(close_me);
	if (close_me < 0)
		die(FD_CLOSE_ERR);
	return (CLOSED_FD);
}

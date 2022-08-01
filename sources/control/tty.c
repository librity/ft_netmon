/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 23:40:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

t_termios	original_tty_attr(void)
{
	return (c()->original_tty_attr);
}

void	save_tty_flags(void)
{
	int				get_result;

	get_result = tcgetattr(STDIN_FILENO, &c()->original_tty_attr);
	if (get_result == -1)
		die(TTY_GET_ATTR_ERR);
}

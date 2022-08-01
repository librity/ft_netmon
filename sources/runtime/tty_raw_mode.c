/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_raw_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:00:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 00:09:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static bool	attr_is_empty(t_termios *attr)
{
	int		i;
	char	*cast;

	i = sizeof(t_termios);
	cast = (char *)attr;
	while (i--)
	{
		if (*cast++ != '\0')
			return (false);
	}
	return (true);
}

void	disable_tty_raw_mode(void)
{
	int	set_result;

	if (attr_is_empty(&c()->original_tty_attr))
		die(TTY_EMPTY_ATTR_ERR);
	set_result = tcsetattr(
			STDIN_FILENO,
			TCSAFLUSH,
			&c()->original_tty_attr
			);
	if (set_result == -1)
		die(TTY_RESTORE_ATTR_ERR);
}

void	enable_tty_raw_mode(void)
{
	struct termios	raw_tty_flags;
	int				set_result;

	if (attr_is_empty(&c()->original_tty_attr))
		die(TTY_EMPTY_ATTR_ERR);
	raw_tty_flags = c()->original_tty_attr;
	raw_tty_flags.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw_tty_flags.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	set_result = tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_tty_flags);
	if (set_result == -1)
		die(TTY_SET_ATTR_ERR);
}

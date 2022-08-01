/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 00:18:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	print_controls(void)
{
	ft_redb_endl(CONTROLS_HELP);
}

static char	read_key(void)
{
	char	input;
	char	read_result;

	read_result = read(STDIN_FILENO, &input, 1);
	while (read_result != 1)
	{
		if (read_result == -1 && errno != EAGAIN)
			die(READ_KEY_ERR);
		read_result = read(STDIN_FILENO, &input, 1);
	}
	return (input);
}

void	handle_key(void)
{
	char	current_key;

	current_key = read_key();
	debug_key(current_key);
	if (current_key == CONTROL_Q)
		quit();
	if (current_key == CONTROL_S)
		print_controls();
	if (current_key == CONTROL_D)
		print_controls();
	if (current_key == CONTROL_C)
		print_controls();
}

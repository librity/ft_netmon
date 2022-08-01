/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:14:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:47:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	print_banner(void)
{
	ft_clear();
	ft_putendl(WELCOME_BANNER);
}

void	initialize(int argc, char **argv)
{
	initialize_control(argc, argv);
	atexit(cleanup);
	enable_tty_raw_mode();
	handle_flags();
	if (help_flag())
		help_and_quit();
	if (simplify_flag())
		simplify_and_quit();
	print_banner();
	handle_config();
}

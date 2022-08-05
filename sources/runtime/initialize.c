/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:14:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 14:29:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	handle_simplify(void)
{
	if (simplify_flag())
		simplify_and_quit();
}

static void	handle_help(void)
{
	if (help_flag())
		help_and_quit();
}

static void	initialize_controls(int argc, char **argv)
{
	initialize_control(argc, argv);
	initialize_thread_pool_control();
}

void	initialize(int argc, char **argv)
{
	initialize_controls(argc, argv);
	atexit(cleanup);
	handle_flags();
	handle_help();
	handle_simplify();
	handle_monitoring();
}

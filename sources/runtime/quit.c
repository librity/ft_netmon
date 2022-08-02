/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:35:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 12:39:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define QUIT_MESSAGE "See ya!\n"

void	quit(void)
{
	ts_printf(GB QUIT_MESSAGE RC);
	exit(EXIT_SUCCESS);
}

void	help_and_quit(void)
{
	ts_printf(HELP_MSG);
	quit();
}

/**
 * TODO: SIMPLIFY!
 */
void	simplify_and_quit(void)
{
	ts_printf("TODO: SIMPLIFY!\n");
	quit();
}

void	close_thread_pool_and_quit(void)
{
	close_thread_pool();
	quit();
}

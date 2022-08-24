/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:12:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	close_files(void)
{
	close_log();
	close_log_fs();
	close_config();
}

void	cleanup(void)
{
	disable_tty_raw_mode();
	close_files();
	free_memory();
}

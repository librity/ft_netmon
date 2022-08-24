/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	debug_file_flags(void)
{
	debug_file_flag(CONFIG_FILE_FLAG_NAME, config_path());
	debug_file_flag(LOG_FILE_FLAG_NAME, log_path());
}

static void	debug_bool_flags(void)
{
	debug_bool_flag(HELP_FLAG_NAME, help_flag());
	debug_bool_flag(SIMPLIFY_FLAG_NAME, simplify_flag());
	debug_bool_flag(DEBUG_FLAG_NAME, debug_flag());
}

static void	debug_int_flags(void)
{
	debug_int_flag(WORKERS_FLAG_NAME, workers_count());
}

void	debug_flags(void)
{
	debug_bool_flags();
	debug_file_flags();
	debug_int_flags();
}

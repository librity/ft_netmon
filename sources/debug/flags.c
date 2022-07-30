/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 17:24:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	debug_file_flag(char *flag_name, char *file_path)
{
	ft_debug("%s path: %s", flag_name, file_path);
}

static void	debug_bool_flag(char *flag_name, bool flag)
{
	if (flag)
		ft_debug("Is %s flag enabled? YES", flag_name);
	else
		ft_debug("Is %s flag enabled? NO", flag_name);
}

static void	debug_file_flags(void)
{
	if (debug())
	{
		debug_file_flag(CONFIG_FILE_FLAG_NAME, config_path());
		debug_file_flag(LOG_FILE_FLAG_NAME, log_path());
	}
}

static void	debug_bool_flags(void)
{
	if (debug())
	{
		debug_bool_flag(HELP_FLAG_NAME, help_flag());
		debug_bool_flag(SIMPLIFY_FLAG_NAME, simplify_flag());
		debug_bool_flag(DEBUG_FLAG_NAME, debug_flag());
	}
}

void	debug_flags(void)
{
	debug_bool_flags();
	debug_file_flags();
}

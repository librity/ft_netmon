/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 18:06:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	**file_flags(void)
{
	static char	*__file_flags[] = {
		CONFIG_FILE_FLAG, LOG_FILE_FLAG, NULL
	};

	return (__file_flags);
}

static void	set_file_flag(char **arguments)
{
	char	*file_path;

	file_path = *(arguments + 1);
	if (file_path == NULL)
		die(FILE_FLAG_NULL_PATH_ERR);
	if (ft_streq(*arguments, CONFIG_FILE_FLAG))
		return (set_config_path(file_path));
	if (ft_streq(*arguments, LOG_FILE_FLAG))
		return (set_log_path(file_path));
}

static bool	next_is_file_path(char **arguments)
{
	char	*next;

	next = *(arguments + 1);
	if (next == NULL)
		return (false);
	if (is_file_flag(next))
		return (false);
	if (is_bool_flag(next))
		return (false);
	return (true);
}

bool	is_file_flag(char *argument)
{
	return (ft_str_in_strarr(file_flags(), argument));
}

bool	handled_file_flag(char **arguments)
{
	if (!is_file_flag(*arguments))
		return (false);
	if (!next_is_file_path(arguments))
		return (false);
	set_file_flag(arguments);
	return (true);
}

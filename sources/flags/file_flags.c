/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 22:22:51 by lpaulo-m         ###   ########.fr       */
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

void	set_file_flags(char **arguments)
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

bool	is_file_flag(char *arg)
{
	char	**flag;

	flag = file_flags();
	while (*flag != NULL)
	{
		if (ft_streq(arg, *flag))
			return (true);
		flag++;
	}
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 20:51:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	remove_comment(char *line)
{
	char	*comment_start;

	comment_start = ft_strchr(line, COMMENT_INDICATOR);
	if (comment_start == NULL)
		return ;
	*comment_start = '\0';
}

static char	**get_fields(char *line)
{
	char	**fields;

	remove_comment(line);
	if (ft_is_empty_str(line))
		return (NULL);
	fields = ft_split(line, FIELD_SEPARATOR);
	return (fields);
}

static void	handle_fields(char **fields)
{
	validate_fields(fields);
	// parse_fields(fields);
	ft_free_strarr(fields);
}

void	handle_config(void)
{
	int		status;
	char	*line;
	char	**fields;

	open_config();
	status = GNL_FOUND_LINEBREAK;
	while (status == GNL_FOUND_LINEBREAK)
	{
		status = ft_gnl(config_fd(), &line);
		if (status == GNL_ERROR)
			free_and_die(line, CONFIG_READ_ERR);
		fields = get_fields(line);
		free(line);
		if (fields == NULL)
			continue ;
		handle_fields(fields);
	}
	close_config();
}

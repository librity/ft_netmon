/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:28:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	remove_comment(char *line)
{
	char	*comment_start;

	comment_start = ft_strchr(line, COMMENT_INDICATOR);
	if (comment_start == NULL)
		return ;
	*comment_start = '\0';
}

static char	**split_fields(char *line)
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
	parse_fields(fields);
	ft_free_strarr(fields);
}

static void	handle_line(int *status)
{
	char	*line;
	char	**fields;

	*status = ft_gnl_or_die(config_fd(), &line);
	fields = split_fields(line);
	free(line);
	if (fields == NULL)
		return ;
	handle_fields(fields);
	return ;
}

void	parse_config_file(void)
{
	int	status;

	open_config();
	status = GNL_FOUND_LINEBREAK;
	while (status == GNL_FOUND_LINEBREAK)
		handle_line(&status);
	close_config();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:39:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	**split_fields(char *line)
{
	char	**fields;

	if (ft_is_empty_str(line))
		return (NULL);
	fields = ft_split(line, FIELD_SEPARATOR);
	return (fields);
}

static void	handle_line(int *status)
{
	char	*line;
	char	**fields;

	*status = ft_gnl_or_die(log_fd(), &line);
	fields = split_fields(line);
	free(line);
	if (fields == NULL)
		return ;
	simplify_fields(fields);
	return ;
}

void	simplify_log(void)
{
	int	status;

	open_log();
	status = GNL_FOUND_LINEBREAK;
	while (status == GNL_FOUND_LINEBREAK)
		handle_line(&status);
	close_log();
}

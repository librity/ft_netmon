/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 19:04:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*log_path(void)
{
	return (c()->log.path);
}

void	set_log_path(char *path)
{
	c()->log.path = path;
}

int	log_fd(void)
{
	return (c()->log.fd);
}

void	open_log(void)
{
	int	fd;

	if (log_fd() != CLOSED_FD)
		die(DOUBLE_OPEN_LOG_ERR);
	fd = open_file_or_die(log_path());
	c()->log.fd = fd;
}

void	close_log(void)
{
	if (log_fd() == CLOSED_FD)
		return ;
	close_or_die(log_fd());
	c()->log.fd = CLOSED_FD;
}

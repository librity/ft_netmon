/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

char	*config_path(void)
{
	return (c()->config.path);
}

void	set_config_path(char *path)
{
	c()->config.path = path;
}

int	config_fd(void)
{
	return (c()->config.fd);
}

void	open_config(void)
{
	int	fd;

	if (config_fd() != CLOSED_FD)
		die(DOUBLE_OPEN_CONFIG_ERR);
	fd = open_file_or_die(config_path());
	c()->config.fd = fd;
}

void	close_config(void)
{
	if (config_fd() == CLOSED_FD)
		return ;
	close_or_die(config_fd());
	c()->config.fd = CLOSED_FD;
}

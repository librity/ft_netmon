/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

int	open_file_or_die(char *path)
{
	int	open_fd;
	int	open_flags;

	open_flags = O_RDONLY;
	open_fd = open(path, open_flags);
	if (open_fd < 0)
		die(FILE_OPEN_ERR);
	return (open_fd);
}

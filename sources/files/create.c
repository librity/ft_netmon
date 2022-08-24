/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

int	create_file_or_die(char *path)
{
	int	open_fd;
	int	create_flags;

	create_flags = O_CREAT | O_WRONLY | O_APPEND;
	open_fd = open(path, create_flags, CREATE_PERMISSION);
	if (open_fd < 0)
		die(FILE_CREATE_ERR);
	return (open_fd);
}

FILE	*create_fs_or_die(char *path)
{
	FILE	*open_fs;

	open_fs = fopen(path, "a");
	if (open_fs == NULL)
		die(FILESTREAM_CREATE_ERR);
	return (open_fs);
}

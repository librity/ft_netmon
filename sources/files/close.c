/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

int	close_or_die(int close_me)
{
	if (close_me == CLOSED_FD)
		die(FD_DOUBLE_CLOSE_ERR);
	close_me = close(close_me);
	if (close_me < 0)
		die(FD_CLOSE_ERR);
	return (CLOSED_FD);
}

FILE	*close_fs_or_die(FILE *close_me)
{
	int	result;

	if (close_me == NULL)
		die(FS_DOUBLE_CLOSE_ERR);
	result = fclose(close_me);
	if (result != 0)
		die(FS_CLOSE_ERR);
	return (NULL);
}

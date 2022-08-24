/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_stream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

FILE	*log_fs(void)
{
	return (c()->log.fs);
}

void	open_log_fs(void)
{
	FILE	*fs;

	if (log_fs() != NULL)
		die(DOUBLE_OPEN_LOG_STREAM_ERR);
	fs = create_fs_or_die(log_path());
	c()->log.fs = fs;
}

void	close_log_fs(void)
{
	if (log_fs() == NULL)
		return ;
	close_fs_or_die(log_fs());
	c()->log.fs = NULL;
}

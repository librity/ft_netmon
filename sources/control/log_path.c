/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 18:39:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

bool	log_path(void)
{
	return (c()->log_path);
}

void	set_log_path(char *path)
{
	c()->log_path = path;
}

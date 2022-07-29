/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 19:42:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*config_path(void)
{
	return (c()->config.path);
}

void	set_config_path(char *path)
{
	c()->config.path = path;
}

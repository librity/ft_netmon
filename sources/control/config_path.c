/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:38:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 18:39:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

bool	config_path(void)
{
	return (c()->config_path);
}

void	set_config_path(char *path)
{
	c()->config_path = path;
}

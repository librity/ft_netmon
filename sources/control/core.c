/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 22:36:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

t_control	*c(void)
{
	static t_control	__control_instance;

	return (&__control_instance);
}

void	initialize_control(int argc, char **argv)
{
	c()->argc = argc;
	c()->argv = argv;
	c()->help_flag = false;
	c()->simplify_flag = false;
	c()->config.path = DEFAULT_CONFIG_PATH;
	c()->config.fd = CLOSED_FD;
	c()->log.path = DEFAULT_LOG_PATH;
	c()->log.fd = CLOSED_FD;
}

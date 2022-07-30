/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 17:26:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	debug_target_count(char *protocol, t_dlist **targets)
{
	ft_debug("%s targets: %d", protocol, ft_dlstsize(*targets));
}

void	debug_targets(void)
{
	if (debug())
	{
		debug_target_count(HTTP, http_targets());
		debug_target_count(PING, ping_targets());
		debug_target_count(DNS, dns_targets());
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 13:12:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define TARGET_FORMAT "\t{ protocol: %s, \
name: %s, \
address.name: %s, \
method: %s, \
code: %s, \
frequency: %d, \
dns.ipv4: %s }"

static void	inspect_target(void *t)
{
	t_target	*target;

	target = (t_target *)t;
	ft_debug(TARGET_FORMAT,
		get_protocol_by_code(target->protocol),
		target->name,
		target->address.name,
		target->method,
		target->code,
		target->frequency,
		target->dns.ipv4);
}

static void	debug_target_count(t_dlist **targets)
{
	ft_debug("Total targets: %d", ft_dlstsize(*targets));
}

void	debug_targets(void)
{
	if (debug())
	{
		debug_target_count(targets());
		ft_debug("TARGETS:");
		ft_dlstiter(*targets(), &inspect_target);
	}
}

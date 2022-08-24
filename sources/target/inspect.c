/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:14:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define TARGET_FORMAT "\t{ protocol: %s, \
name: %s, \
address.name: %s, \
method: %s, \
code: %s, \
frequency: %d, \
dns.ipv4: %s }"

void	inspect_target(void *t)
{
	t_target	*target;

	target = (t_target *)t;
	ft_bdebug(debug(), TARGET_FORMAT,
		get_protocol_by_code(target->protocol),
		target->name,
		target->address.name,
		target->method,
		target->code,
		target->frequency_sec,
		target->dns.ipv4);
}

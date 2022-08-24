/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	handle_request(t_target *target)
{
	const t_protocol	protocol = target->protocol;

	if (protocol == HTTP_PROT)
		return (handle_http_request(target));
	if (protocol == HTTPS_PROT)
		return (handle_https_request(target));
	if (protocol == PING_PROT)
		return (handle_ping_request(target));
	if (protocol == DNS_PROT)
		return (handle_dns_request(target));
	print_error(BAD_PROTOCOL_ERR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 04:41:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	handle_http_request(t_target *target)
{
	(void)target;
	ts_fprintf(stdout, "MOCK PINGING HTTP\n");
}

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

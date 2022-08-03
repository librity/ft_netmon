/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 15:18:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	log_request(t_request *request)
{
	const t_protocol	protocol = request->target->protocol;

	if (protocol == HTTP_PROT)
		return (log_http_request(request));
	if (protocol == HTTPS_PROT)
		return (log_https_request(request));
	if (protocol == PING_PROT)
		return (log_ping_request(request));
	if (protocol == DNS_PROT)
		return (log_dns_request(request));
	print_error(BAD_PROTOCOL_ERR);
}

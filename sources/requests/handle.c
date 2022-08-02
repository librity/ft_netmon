/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 00:26:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	handle_http_request(t_target *target)
{
	(void)target;
	ts_fprintf(stdout, "MOCK PINGING HTTP\n");
}

void	handle_ping_request(t_target *target)
{
	(void)target;
	ts_fprintf(stdout, "MOCK PINGING PING\n");
}

void	handle_dns_request(t_target *target)
{
	(void)target;
	ts_fprintf(stdout, "MOCK PINGING DNS\n");
}

void	handle_request(t_target *target)
{
	if (target->protocol == HTTP_PROT)
		return (handle_http_request(target));
	if (target->protocol == HTTPS_PROT)
		return (handle_https_request(target));
	if (target->protocol == PING_PROT)
		return (handle_ping_request(target));
	if (target->protocol == DNS_PROT)
		return (handle_dns_request(target));
	tdie(BAD_PROTOCOL_ERR);
}

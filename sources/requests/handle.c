/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 22:28:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	handle_http_request(t_target *request)
{
	request = request;
	ts_fprintf(stdout, "MOCK PINGING HTTP\n");
}

void	handle_https_request(t_target *request)
{
	request = request;
	ts_fprintf(stdout, "MOCK PINGING HTTPS\n");
}

void	handle_ping_request(t_target *request)
{
	request = request;
	ts_fprintf(stdout, "MOCK PINGING PING\n");
}

void	handle_dns_request(t_target *request)
{
	request = request;
	ts_fprintf(stdout, "MOCK PINGING DNS\n");
}

void	handle_request(t_target *request)
{
	if (request->protocol == HTTP_PROT)
		return (handle_http_request(request));
	if (request->protocol == HTTPS_PROT)
		return (handle_https_request(request));
	if (request->protocol == PING_PROT)
		return (handle_ping_request(request));
	if (request->protocol == DNS_PROT)
		return (handle_dns_request(request));
	tdie(BAD_PROTOCOL_ERR);
}

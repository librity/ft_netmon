/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:35:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	handle_http_request(t_target *request)
{
	request = request;
	tdebug("MOCK PINGING HTTP");
}

void	handle_https_request(t_target *request)
{
	request = request;
	tdebug("MOCK PINGING HTTPS");
}

void	handle_ping_request(t_target *request)
{
	request = request;
	tdebug("MOCK PINGING PING");
}

void	handle_dns_request(t_target *request)
{
	request = request;
	tdebug("MOCK PINGING DNS");
}

void	handle_request(t_target *request)
{
	if (request->protocol == HTTP_CODE)
		return (handle_http_request(request));
	if (request->protocol == HTTPS_CODE)
		return (handle_https_request(request));
	if (request->protocol == PING_CODE)
		return (handle_ping_request(request));
	if (request->protocol == DNS_CODE)
		return (handle_dns_request(request));
	tdebug("INVALID REQUEST CODE");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	set_sockaddr(t_inet_sockaddr *socket_address, char *ipv4)
{
	(*socket_address).sin_family = AF_INET;
	(*socket_address).sin_port = htons(AUTOMATIC_PORT_NUMBER);
	(*socket_address).sin_addr.s_addr = inet_addr(ipv4);
}

static char	*get_ip(t_ping *p)
{
	p->req->ipv4 = lookup_ipv4(p->req->target->address.name);
	if (p->req->ipv4 == NULL)
		return (PING_DNS_ERR);
	return (NULL);
}

void	ping_prepare_address(t_ping *p)
{
	p->err = get_ip(p);
	if (p->err != NULL)
		return ;
	set_sockaddr(&p->sendaddr, p->req->ipv4);
}

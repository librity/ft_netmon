/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/04 22:26:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*get_ipv4(t_http *h)
{
	h->req->ipv4 = lookup_ipv4(h->req->target->address.name);
	if (h->req->ipv4 == NULL)
		return (HTTP_DNS_ERR);
	return (NULL);
}

static char	*set_socket_address(t_http *h)
{
	int	result;

	ft_bzero(&h->servaddr, sizeof(h->servaddr));
	h->servaddr.sin_family = AF_INET;
	h->servaddr.sin_port = htons(HTTP_SERVER_PORT);
	result = inet_pton(AF_INET, h->req->ipv4, &h->servaddr.sin_addr);
	if (result <= 0)
		return (HTTP_ADDRESS_ERR);
	return (NULL);
}

void	http_prepare_address(t_http *h)
{
	h->err = get_ipv4(h);
	if (h->err != NULL)
		return ;
	h->err = set_socket_address(h);
}

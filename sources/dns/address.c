/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 02:51:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	dns_prepare_address(t_dns *d)
{
	ft_bzero(&d->addr, sizeof(d->addr));
	d->addr.sin_family = AF_INET;
	d->addr.sin_addr.s_addr = inet_addr(d->req->target->dns.ipv4);
	d->addr.sin_port = htons(DNS_PORT);
}

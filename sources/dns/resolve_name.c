/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 11:57:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	prepare_server_address(t_dns *d)
{
	ft_bzero(&d->addr, sizeof(d->addr));
	d->addr.sin_family = AF_INET;
	d->addr.sin_addr.s_addr = inet_addr(d->req->target->dns.ipv4);
	d->addr.sin_port = htons(DNS_PORT);
}

static bool	found_ip(t_dns *d, int i)
{
	return (d->res_buff[i] == 0xC0 && d->res_buff[i + 3] == 0x01);
}

static void	save_ip(t_dns *d, int i)
{
	d->req->ipv4 = ft_salloc(IPV4_ADDRESS_STRING_SIZE);
	sprintf(d->req->ipv4, "%u.%u.%u.%u",
		d->res_buff[i],
		d->res_buff[i + 1],
		d->res_buff[i + 2],
		d->res_buff[i + 3]);
}

void	extract_ip(t_dns *d)
{
	int		i;

	i = 0;
	while (i < d->bytes_received)
	{
		if (found_ip(d, i))
		{
			i += 12;
			save_ip(d, i);
			return ;
		}
		i++;
	}
	d->err = DNS_NO_IPS_ERR;
}

char	*resolve_name(t_request *request)
{
	t_dns	d;

	d.req = request;
	prepare_query(&d);
	prepare_server_address(&d);
	dns_send_and_receive(&d);
	if (d.err != NULL)
		return (d.err);
	extract_ip(&d);
	if (d.err != NULL)
		return (d.err);
	return (NULL);
}

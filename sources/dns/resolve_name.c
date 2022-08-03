/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 10:40:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>


// static void	write_header(t_dns *d)
// {

// }

void	prepare_query(t_dns *d)
{
	char	**free_me;
	char	**words;
	char	*word;
	int		i;
	const unsigned char	header[] =  {0xDB, 0x42, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00};

	d->query.req_type = 0x01;
	d->query.length = 12;
	ft_memcpy(d->query.message, header, d->query.length);

	words = ft_split(d->req->target->address.name, '.');
	free_me = words;
	while (*words != NULL)
	{
		word = *words;
		d->query.message[d->query.length++] = ft_strlen(word);
		i = 0;
		while (i < (int)ft_strlen(word))
		{
			d->query.message[d->query.length++] = word[i];
			i++;
		}
		words++;
	}
	ft_free_strarr(free_me);

	d->query.message[d->query.length++] = 0x00;
	d->query.message[d->query.length++] = 0x00;
	d->query.message[d->query.length++] = d->query.req_type;
	d->query.message[d->query.length++] = 0x00;
	d->query.message[d->query.length++] = 0x01;
}

char	*resolve_name(t_request *request)
{
	t_dns	d;

	d.req = request;
	prepare_query(&d);
	d.socket = create_datagram_socket();
	if (d.socket < 0)
		return (GENERIC_ERR);
	ft_memset(&d.addr, 0, sizeof(d.addr));
	d.addr.sin_family = AF_INET;
	d.addr.sin_addr.s_addr = inet_addr(d.req->target->dns.ipv4);
	d.addr.sin_port = htons(DNS_PORT);
	d.size = sizeof(d.addr);
	d.ret = sendto(d.socket, d.query.message, d.query.length, 0,
			(t_sockaddr *)&d.addr, d.size);
	if (d.ret < 0)
		return (GENERIC_ERR);
	ft_memset(&d.buffer, 0, DNS_BUFFER_SIZE);
	d.ret = recvfrom(d.socket, d.buffer, DNS_BUFFER_SIZE, 0,
			(t_sockaddr *)&d.addr, (unsigned int *)&d.size);
	close(d.socket);
	if (d.ret < 0)
		return (GENERIC_ERR);
	d.rcode = (d.buffer[3] & 0x0F);
	if (d.rcode == 2)
		return (GENERIC_ERR);
	if (d.rcode == 3)
		return (GENERIC_ERR);
	if (d.query.req_type != 0x01)
		return (GENERIC_ERR);
	for (d.i = 0; d.i < d.ret; d.i++)
	{
		if (d.buffer[d.i] == 0xC0 && d.buffer[d.i + 3] == 0x01)
		{
			d.ip++;
			d.i += 12;
			d.req->ipv4 = ft_salloc(IPV4_ADDRESS_STRING_SIZE);
			sprintf(d.req->ipv4, "%u.%u.%u.%u", d.buffer[d.i], d.buffer[d.i + 1], d.buffer[d.i + 2], d.buffer[d.i + 3]);
		}
	}
	if (!d.ip)
		return (GENERIC_ERR);
	tdebug(d.req->ipv4);
	return (NULL);
}

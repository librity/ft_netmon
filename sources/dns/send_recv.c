/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:01:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 02:52:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*send_query(t_dns *d)
{
	int	result;

	d->socket = create_datagram_socket();
	if (d->socket < 0)
		return (DNS_DATAGRAM_SOCKET_ERR);
	result = sendto(d->socket, d->query.message, d->query.length, 0,
			(t_sockaddr *)&d->addr, sizeof(d->addr));
	if (result < 0)
		return (DNS_SEND_ERR);
	return (NULL);
}

static char	*receive_response(t_dns *d)
{
	unsigned int	address_size;

	address_size = sizeof(d->addr);
	ft_memset(&d->res_buff, 0, DNS_BUFFER_SIZE);
	d->bytes_received = recvfrom(d->socket, d->res_buff, DNS_BUFFER_SIZE, 0,
			(t_sockaddr *)&d->addr, &address_size);
	stop_clock(d->req);
	close(d->socket);
	if (d->bytes_received < 0)
		return (DNS_RECEIVE_ERR);
	return (NULL);
}

#define RETURN_CODE_FLAG 0x0F

static char	*validate_return_code(t_dns *d)
{
	int	return_code;

	return_code = (d->res_buff[3] & RETURN_CODE_FLAG);
	if (return_code == 2)
		return (DNS_SERVER_ERR);
	if (return_code == 3)
		return (DNS_NOT_FOUND_ERR);
	return (NULL);
}

void	dns_send_and_receive(t_dns *d)
{
	start_clock(d->req);
	d->err = send_query(d);
	if (d->err != NULL)
		return ;
	d->err = receive_response(d);
	if (d->err != NULL)
		return ;
	d->err = validate_return_code(d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:01:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	*send_packet(t_ping *p)
{
	int	result;

	result = sendto(p->raw_socket, &p->packet, sizeof(p->packet), 0,
			(t_sockaddr *)&p->sendaddr, sizeof(p->sendaddr));
	if (result <= 0)
		return (PING_PACKET_ERR);
	return (NULL);
}

static char	*receive_response(t_ping *p)
{
	int				result;
	unsigned int	address_size;

	address_size = sizeof(p->recvaddr);
	result = recvfrom(p->raw_socket, &p->packet, sizeof(p->packet), 0,
			(struct sockaddr *)&p->recvaddr, (unsigned int *)&address_size);
	close(p->raw_socket);
	if (result <= 0)
		return (PING_RECEIVE_ERR);
	return (NULL);
}

static bool	is_echo_reply(t_ping *p)
{
	if (p->packet.hdr.type != PING_ECHO_REPLY_TYPE)
		return (false);
	if (p->packet.hdr.code != PING_ECHO_REPLY_CODE)
		return (false);
	return (true);
}

void	ping_send_and_receive(t_ping *p)
{
	start_clock(p->req);
	p->err = send_packet(p);
	if (p->err != NULL)
		return ;
	p->err = receive_response(p);
	if (p->err != NULL)
		return ;
	stop_clock(p->req);
	if (!is_echo_reply(p))
		p->err = PING_CODE_ERR;
}

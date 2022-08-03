/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:01:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 04:02:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

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
	int	result;

	p->address_length = sizeof(p->recvaddr);
	result = recvfrom(p->raw_socket, &p->packet, sizeof(p->packet), 0,
			(struct sockaddr *)&p->recvaddr,
			(unsigned int *)&p->address_length);
	end_clock(p->req);
	if (result <= 0)
		return (PING_RECEIVE_ERR);
	return (NULL);
}

void	send_and_receive(t_ping *p)
{
	start_clock(p->req);
	p->err = send_packet(p);
	if (p->err != NULL)
		return ;
	p->err = receive_response(p);
	if (p->err != NULL)
		return ;
	if (!(p->packet.hdr.type == 69 && p->packet.hdr.code == 0))
		p->err = PING_CODE_ERR;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 03:15:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static unsigned short	calculate_checksum(unsigned short *bytes, int len)
{
	unsigned int	sum;
	unsigned short	result;

	sum = 0;
	while (len > 1)
	{
		sum += *bytes++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char *)bytes;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}

static void	set_sockaddr(t_inet_sockaddr *socket_address, char *ipv4)
{
	(*socket_address).sin_family = AF_INET;
	(*socket_address).sin_port = htons(AUTOMATIC_PORT_NUMBER);
	(*socket_address).sin_addr.s_addr = inet_addr(ipv4);
}

static char	*set_time_to_live(int raw_socket)
{
	int	time_to_live;
	int	result;

	time_to_live = PING_TIME_TO_LIVE;
	result = setsockopt(raw_socket, SOL_IP, IP_TTL, &time_to_live,
			sizeof(time_to_live));
	if (result != 0)
		return (PING_TTL_ERR);
	return (NULL);
}

static char	*set_timeout(int raw_socket)
{
	t_timeval	tv_out;
	int			result;

	tv_out.tv_sec = PING_RECEIVE_TIMEOUT;
	tv_out.tv_usec = 0;
	result = setsockopt(raw_socket, SOL_SOCKET, SO_RCVTIMEO,
			(const char *)&tv_out, sizeof(tv_out));
	if (result != 0)
		return (PING_TIMEOUT_ERR);
	return (NULL);
}

static void	prepare_packet(t_ping_packet *packet)
{
	int	i;

	ft_bzero(packet, sizeof(*packet));
	packet->hdr.type = ICMP_ECHO;
	packet->hdr.un.echo.id = getpid();
	i = 0;
	while (i < (int)sizeof(packet->msg) - 1)
	{
		packet->msg[i] = i + '0';
		i++;
	}
	packet->msg[i] = 0;
	packet->hdr.checksum = calculate_checksum((unsigned short *)packet, sizeof(*packet));
}

char	*ping_target(t_request *request)
{
	t_ping	p;

	request->ipv4 = lookup_ipv4(request->target->address.name);
	if (request->ipv4 == NULL)
		return (PING_DNS_ERR);
	set_sockaddr(&p.sendaddr, request->ipv4);
	p.raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (p.raw_socket < 0)
		return (PING_RAW_SOCKET_ERR);
	p.err = set_time_to_live(p.raw_socket);
	if (p.err != NULL)
		return (p.err);
	p.err = set_timeout(p.raw_socket);
	if (p.err != NULL)
		return (p.err);
	prepare_packet(&p.packet);
	start_clock(request);
	p.result = sendto(p.raw_socket, &p.packet, sizeof(p.packet), 0,
			(t_sockaddr *)&p.sendaddr, sizeof(p.sendaddr));
	if (p.result <= 0)
		return (PING_PACKET_ERR);
	p.address_length = sizeof(p.recvaddr);
	p.result = recvfrom(p.raw_socket, &p.packet, sizeof(p.packet), 0,
			(struct sockaddr *)&p.recvaddr, (unsigned int *)&p.address_length);
	end_clock(request);
	if (p.result <= 0)
		return (PING_RECEIVE_ERR);
	if (!(p.packet.hdr.type == 69 && p.packet.hdr.code == 0))
		return (PING_CODE_ERR);
	return (NULL);
}

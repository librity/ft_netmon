/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static uint16_t	calculate_checksum(unsigned short *bytes, int len)
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

void	ping_prepare_packet(t_ping_packet *packet)
{
	int	i;

	ft_bzero(packet, sizeof(*packet));
	packet->hdr.type = ICMP_ECHO;
	packet->hdr.un.echo.id = getpid();
	i = 0;
	while (i < (int) sizeof(packet->msg) - 1)
	{
		packet->msg[i] = i + '0';
		i++;
	}
	packet->msg[i] = 0;
	packet->hdr.checksum = calculate_checksum(
			(unsigned short *)packet,
			sizeof(*packet));
}

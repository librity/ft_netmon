/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 14:01:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	prepare_packet(t_ping_packet *packet)
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

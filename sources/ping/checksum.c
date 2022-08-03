/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:55:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 03:57:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

uint16_t	calculate_checksum(unsigned short *bytes, int len)
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

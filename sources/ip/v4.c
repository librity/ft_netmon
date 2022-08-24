/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

bool	is_valid_ipv4(char *address)
{
	unsigned char	_buffer[sizeof(struct in6_addr)];
	int				result;

	result = inet_pton(AF_INET, address, _buffer);
	if (result == -1)
		die(IPV4_VALIDATION_ERR);
	if (result == 0)
		return (false);
	return (true);
}

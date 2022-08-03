/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:14:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 03:32:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

bool	can_use_raw_sockets(void)
{
	int	raw_socket;

	raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (raw_socket < 0)
		return (false);
	close(raw_socket);
	return (true);
}

int	create_raw_socket(void)
{
	int	raw_socket;

	raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	return (raw_socket);
}

int	create_raw_socket_or_die(void)
{
	int	raw_socket;

	raw_socket = create_raw_socket();
	if (raw_socket < 0)
		die(RAW_SOCKET_CREATE_ERR);
	return (raw_socket);
}

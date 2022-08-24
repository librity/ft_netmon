/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

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

static char	*create_socket(t_ping *p)
{
	p->raw_socket = create_raw_socket();
	if (p->raw_socket < 0)
		return (PING_RAW_SOCKET_ERR);
	return (NULL);
}

void	ping_prepare_socket(t_ping *p)
{
	p->err = create_socket(p);
	if (p->err != NULL)
		return ;
	p->err = set_time_to_live(p->raw_socket);
	if (p->err != NULL)
		return ;
	p->err = set_timeout(p->raw_socket);
}

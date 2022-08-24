/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	*create_socket(t_http *h)
{
	h->socket = socket(AF_INET, SOCK_STREAM, 0);
	if (h->socket < 0)
		return (HTTP_SOCKET_ERR);
	return (NULL);
}

static char	*set_socket_timeout(t_http *h)
{
	t_timeval	socket_timeout;
	int			result;

	socket_timeout.tv_sec = HTTP_SOCKET_TIMEOUT_SECS;
	socket_timeout.tv_usec = 0;
	result = setsockopt(h->socket, SOL_SOCKET, SO_RCVTIMEO,
			(const char *)&socket_timeout, sizeof(socket_timeout));
	if (result < 0)
		return (HTTP_SOCKET_ERR);
	return (NULL);
}

void	http_prepare_socket(t_http *h)
{
	h->err = create_socket(h);
	if (h->err != NULL)
		return ;
	h->err = set_socket_timeout(h);
}

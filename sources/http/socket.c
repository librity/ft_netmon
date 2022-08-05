/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/04 21:09:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*create_socket(t_http *h)
{
	h->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (h->sockfd < 0)
		return (HTTP_SOCKET_ERR);
	return (NULL);
}

static char	*set_socket_timeout(t_http *h)
{
	int	result;

	h->tv.tv_sec = HTTP_SOCKET_TIMEOUT_SECS;
	h->tv.tv_usec = 0;
	result = setsockopt(h->sockfd, SOL_SOCKET, SO_RCVTIMEO,
			(const char *)&h->tv, sizeof(h->tv));
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

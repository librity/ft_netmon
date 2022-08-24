/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	*connect_to_server(t_http *h)
{
	int	result;

	result = connect(h->socket, (t_sockaddr *)&h->servaddr,
			sizeof(h->servaddr));
	if (result < 0)
		return (HTTP_CONNECT_ERR);
	return (NULL);
}

static char	*send_request(t_http *h)
{
	size_t	bytes_sent;
	size_t	result;

	ft_memcpy(h->send_buffer, h->content, ft_strsize(h->content));
	bytes_sent = strlen(h->send_buffer);
	result = write(h->socket, h->send_buffer, bytes_sent);
	if (result != bytes_sent)
		return (HTTP_WRITE_ERR);
	return (NULL);
}

static char	*read_response(t_http *h)
{
	ssize_t	bytes_read;

	while (true)
	{
		bytes_read = read(h->socket, h->recv_buffer, HTTP_BUFFER_SIZE - 1);
		if (bytes_read <= 0)
			break ;
		ft_join_lstr_str(&h->req->response, h->recv_buffer, bytes_read);
	}
	close(h->socket);
	return (NULL);
}

void	http_send_and_receive(t_http *h)
{
	start_clock(h->req);
	h->err = connect_to_server(h);
	if (h->err != NULL)
		return ;
	h->err = send_request(h);
	if (h->err != NULL)
		return ;
	h->err = read_response(h);
	stop_clock(h->req);
}

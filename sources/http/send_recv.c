/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 00:06:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*connect_to_server(t_http *h)
{
	int	result;

	result = connect(h->sockfd, (t_sockaddr *)&h->servaddr,
			sizeof(h->servaddr));
	if (result < 0)
		return (HTTP_CONNECT_ERR);
	return (NULL);
}

static char	*send_request(t_http *h)
{
	int	result;

	ft_memcpy(h->sendline, h->request, ft_strsize(h->request));
	h->sendbytes = strlen(h->sendline);
	result = write(h->sockfd, h->sendline, h->sendbytes);
	if (result != h->sendbytes)
		return (HTTP_WRITE_ERR);
	return (NULL);
}

static char	*read_response(t_http *h)
{
	int	bytes_read;

	ft_bzero(h->recvline, HTTP_BUFFER_SIZE);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(h->sockfd, h->recvline, HTTP_BUFFER_SIZE - 1);
		ft_join_lstr_str(&h->req->response, h->recvline, bytes_read);
	}
	close(h->sockfd);
	if (bytes_read < 0)
		return (HTTP_READ_ERR);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 02:44:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	initialize_http(t_http *h, t_request *request)
{
	ft_bzero(h, sizeof(*h));
	h->req = request;
}

char	*handle_http(t_request *request)
{
	t_http	h;

	initialize_http(&h, request);
	http_prepare_content(&h);
	if (h.err != NULL)
		return (h.err);
	http_prepare_address(&h);
	if (h.err != NULL)
		return (h.err);
	http_prepare_socket(&h);
	if (h.err != NULL)
		return (h.err);
	http_send_and_receive(&h);
	if (h.err != NULL)
		return (h.err);
	http_validate_response(&h);
	if (h.err != NULL)
		return (h.err);
	return (NULL);
}

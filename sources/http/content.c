/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:31:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	*resolve_content(t_http *h)
{
	char	*method;

	method = h->req->target->method;
	if (ft_streq(method, HTTP_METHOD_GET))
		return (HTTP_GET_REQUEST);
	if (ft_streq(method, HTTP_METHOD_HEAD))
		return (HTTP_HEAD_REQUEST);
	if (ft_streq(method, HTTP_METHOD_POST))
		return (HTTP_POST_REQUEST);
	if (ft_streq(method, HTTP_METHOD_DELETE))
		return (HTTP_DELETE_REQUEST);
	if (ft_streq(method, HTTP_METHOD_CONNECT))
		return (HTTP_CONNECT_REQUEST);
	if (ft_streq(method, HTTP_METHOD_OPTIONS))
		return (HTTP_OPTIONS_REQUEST);
	if (ft_streq(method, HTTP_METHOD_TRACE))
		return (HTTP_TRACE_REQUEST);
	if (ft_streq(method, HTTP_METHOD_PATCH))
		return (HTTP_PATCH_REQUEST);
	return (NULL);
}

void	http_prepare_content(t_http *h)
{
	h->content = resolve_content(h);
	if (h->content == NULL)
		h->err = HTTP_METHOD_ERR;
}

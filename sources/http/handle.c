/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 00:20:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*handle_http(t_request *request)
{
	t_http	h;

	h.req = request;
	h.err = NULL;
	http_prepare_request(&h);
	if (h.err != NULL)
	{
		tdebug("dsadsadsadsadsad");
		return (h.err);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	initialize_http_request(t_request *request, t_target *target)
{
	initialize_request(request, target);
	request->url = ft_strjoin(HTTP_URL_PREFIX, request->target->address.name);
}

#define DEBUG_FMT "\nHTTP RESPONSE\033[0;34m\n%s\n====================\n"

void	handle_http_request(t_target *target)
{
	t_request	request;
	char		*error_message;

	initialize_http_request(&request, target);
	error_message = handle_http(&request);
	tdebug(BB DEBUG_FMT RB, request.response.ptr);
	if (error_message != NULL)
		return (handle_request_error(&request, error_message));
	handle_request_success(&request);
}

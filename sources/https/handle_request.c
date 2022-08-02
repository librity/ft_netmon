/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:47:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	initialize_https_request(t_request *request, t_target *target)
{
	initialize_request(request, target);
	request->url = ft_strjoin(HTTPS_URL_PREFIX, request->target->address.name);
}

#define RESPONSE_FMT "\nHTTPS RESPONSE\033[0;34m\n%s\n====================\n"

void	handle_https_request(t_target *target)
{
	t_request	request;
	char		*error_message;

	initialize_https_request(&request, target);
	error_message = handle_curl_request(&request);
	tdebug(BB RESPONSE_FMT RB, request.response.ptr);
	if (error_message != NULL)
		return (handle_request_error(&request, error_message));
	handle_request_success(&request);
}


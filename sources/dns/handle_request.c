/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define DEBUG_FMT "DNS QUERY RESULT: \033[0;34m%s"

void	handle_dns_request(t_target *target)
{
	t_request	request;
	char		*error_message;

	initialize_request(&request, target);
	error_message = handle_dns(&request);
	tdebug(BB DEBUG_FMT RB, request.ipv4);
	if (error_message != NULL)
		return (handle_request_error(&request, error_message));
	handle_request_success(&request);
}

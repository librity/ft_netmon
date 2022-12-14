/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define DEBUG_FMT "PINGED IP: \033[0;34m%s"

void	handle_ping_request(t_target *target)
{
	t_request	request;
	char		*error_message;

	initialize_request(&request, target);
	error_message = handle_ping(&request);
	tdebug(BB DEBUG_FMT RB, request.ipv4);
	if (error_message != NULL)
		return (handle_request_error(&request, error_message));
	handle_request_success(&request);
}

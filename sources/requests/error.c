/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	set_request_error(t_request *request, char *error_message)
{
	request->error = true;
	request->error_message = error_message;
}

static void	put_error(t_request *request)
{
	t_req_error	req_error;

	req_error.time = ts_raw_to_logtime(&request->end);
	req_error.name = request->target->name;
	req_error.address = request->target->address.name;
	req_error.protocol = get_protocol_by_code(request->target->protocol);
	req_error.error_message = request->error_message;
	put_request_error(req_error);
	free(req_error.time);
}

void	handle_request_error(t_request *request, char *error_message)
{
	end_time(request);
	set_request_error(request, error_message);
	put_error(request);
	log_request(request);
	destroy_request(request);
}

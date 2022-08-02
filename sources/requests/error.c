/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:36:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	set_request_error(t_request *request, char *error_message)
{
	request->error = true;
	request->error_message = error_message;
}

#define ERROR_MSG "%s - %s request error, %s: %s\n"

static void	put_request(t_request *request)
{
	char	*time;
	char	*protocol;
	char	*address;
	char	*error_message;

	time = ts_raw_to_asctime(&request->end);
	protocol = get_protocol_by_code(request->target->protocol);
	address = request->target->address.name;
	error_message = request->error_message;
	ts_printf(RB ERROR_MSG RC, time, protocol, address, error_message);
	free(time);
}

void	handle_request_error(t_request *request, char *error_message)
{
	end_time(request);
	set_request_error(request, error_message);
	put_request(request);
	log_request(request);
	destroy_request(request);
}

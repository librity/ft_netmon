/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	set_request_error(t_request *request, char *error_message)
{
	request->error = true;
	request->error_message = error_message;
}

#define ERROR_FMT "\
\033[1;36m[\033[0;35m%s\033[1;36m] \
\033[1;31m%s (%s) on %s \033[0;31mrequest error: \
\033[1;34m%s\n\
"

static void	put_request(t_request *request)
{
	char	*time;
	char	*name;
	char	*protocol;
	char	*address;
	char	*error_message;

	time = ts_raw_to_logtime(&request->end);
	name = request->target->name;
	address = request->target->address.name;
	protocol = get_protocol_by_code(request->target->protocol);
	error_message = request->error_message;
	ts_printf(ERROR_FMT RC, time, name, address, protocol, error_message);
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

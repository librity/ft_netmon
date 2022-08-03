/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 03:26:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define SUCCESS_FMT "\
\033[1;36m[\033[0;35m%s\033[1;36m] \
\033[1;32m%s (%s) on %s \033[0;32mis up (latency: %f ms).\n\
"

static void	put_request(t_request *request)
{
	char	*time;
	char	*protocol;
	char	*name;
	char	*address;
	double	latency;

	time = ts_raw_to_logtime(&request->end);
	protocol = get_protocol_by_code(request->target->protocol);
	name = request->target->name;
	address = request->target->address.name;
	latency = request->latency_msec;
	ts_printf(SUCCESS_FMT RC, time, name, address, protocol, latency);
	free(time);
}

void	handle_request_success(t_request *request)
{
	end_time(request);
	put_request(request);
	log_request(request);
	destroy_request(request);
}

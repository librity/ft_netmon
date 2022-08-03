/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 13:22:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	put_success(t_request *request)
{
	t_req_success	req_success;

	req_success.time = ts_raw_to_logtime(&request->end);
	req_success.protocol = get_protocol_by_code(request->target->protocol);
	req_success.name = request->target->name;
	req_success.address = request->target->address.name;
	req_success.latency = request->latency_msec;
	put_request_success(req_success);
	free(req_success.time);
}

void	handle_request_success(t_request *request)
{
	end_time(request);
	put_success(request);
	log_request(request);
	destroy_request(request);
}

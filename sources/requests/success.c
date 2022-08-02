/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:36:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define SUCCESS_MSG "%s - %s on %s is up.\n"

static void	put_request(t_request *request)
{
	char	*time;
	char	*protocol;
	char	*address;

	time = ts_raw_to_asctime(&request->end);
	protocol = get_protocol_by_code(request->target->protocol);
	address = request->target->address.name;
	ts_printf(GB SUCCESS_MSG RC, time, address, protocol);
	free(time);
}

void	handle_request_success(t_request *request)
{
	end_time(request);
	put_request(request);
	log_request(request);
	destroy_request(request);
}

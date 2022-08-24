/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	initialize_log(t_log *log, t_request *request)
{
	log->type = resolve_log_type(request);
	log->start = ts_raw_to_logtime(&request->start);
	log->end = ts_raw_to_logtime(&request->end);
	log->protocol = get_protocol_by_code(request->target->protocol);
	log->name = request->target->name;
	log->address = request->target->address.name;
	log->has_error = resolve_log_error(request);
	log->error_message = request->error_message;
	log->latency_msec = request->latency_msec;
	log->ipv4 = request->ipv4;
	log->frequency_sec = request->target->frequency_sec;
}

#define LOG_FMT "\
%s\t\
START: %s\t\
END: %s\t\
PROTOCOL: %s\t\
NAME: %s\t\
ADDRESS: %s\t\
HAS_ERROR: %s\t\
ERROR_MESSAGE: %s\t\
LATENCY_MILLISEC: %f\t\
IPV4: %s\t\
FREQUENCY_SEC: %d\n\
"

static void	write_log(t_log *log)
{
	ts_fprintf(log_fs(), LOG_FMT,
		log->type,
		log->start,
		log->end,
		log->protocol,
		log->name,
		log->address,
		log->has_error,
		log->error_message,
		log->latency_msec,
		log->ipv4,
		log->frequency_sec);
}

void	log_ping_request(t_request *request)
{
	t_log	log;

	initialize_log(&log, request);
	write_log(&log);
	destroy_log(&log);
}

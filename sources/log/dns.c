/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 12:30:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	initialize_log(t_log *log, t_request *request)
{
	log->type = resolve_log_type(request);
	log->start = ts_raw_to_logtime(&request->start);
	log->end = ts_raw_to_logtime(&request->end);
	log->protocol = get_protocol_by_code(request->target->protocol);
	log->name = request->target->name;
	log->domain = request->target->address.name;
	log->dns_ip = request->target->dns.ipv4;
	log->ip = request->ipv4;
	log->frequency_sec = request->target->frequency_sec;
	log->latency_msec = request->latency_msec;
	log->error_message = request->error_message;
}

#define LOG_FMT "\
%s\t\
START: %s\t\
END: %s\t\
PROTOCOL: %s\t\
NAME: %s\t\
DOMAIN: %s\t\
DNS_SERVER: %s\t\
IPV4: %s\t\
FREQUENCY_SEC: %d\t\
LATENCY_MILLISEC: %f\t\
ERROR_MESSAGE: %s\n\
"

static void	write_log(t_log *log)
{
	ts_fprintf(log_fs(), LOG_FMT,
		log->type,
		log->start,
		log->end,
		log->protocol,
		log->name,
		log->domain,
		log->dns_ip,
		log->ip,
		log->frequency_sec,
		log->latency_msec,
		log->error_message);
}

void	log_dns_request(t_request *request)
{
	t_log	log;

	initialize_log(&log, request);
	write_log(&log);
	destroy_log(&log);
}

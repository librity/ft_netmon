/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   https.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 04:17:29 by lpaulo-m         ###   ########.fr       */
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
	log->url = request->url;
	log->frequency_sec = request->target->frequency_sec;
	log->method = request->target->method;
	log->target_code = request->target->code;
	log->response_code = request->code;
	log->response_length = ft_strlen(request->response.ptr);
	log->latency_msec = request->latency_msec;
	log->error_message = request->error_message;
}

#define LOG_FMT "\
%s\t\
START: %s\t\
END: %s\t\
PROTOCOL: %s\t\
NAME: %s\t\
URL: %s\t\
FREQUENCY_SEC: %d\t\
METHOD: %s\t\
TARGET_CODE: %s\t\
RESPONSE_CODE: %s\t\
RESPONSE_LENGTH: %d\t\
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
		log->url,
		log->frequency_sec,
		log->method,
		log->target_code,
		log->response_code,
		log->response_length,
		log->latency_msec,
		log->error_message);
}

void	log_https_request(t_request *request)
{
	t_log	log;

	initialize_log(&log, request);
	write_log(&log);
	destroy_log(&log);
}

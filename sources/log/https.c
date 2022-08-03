/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   https.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 21:05:24 by lpaulo-m         ###   ########.fr       */
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
	log->frequency = request->target->frequency;
	log->method = request->target->method;
	log->target_code = request->target->code;
	log->response_code = request->code;
	log->response_length = ft_strlen(request->response.ptr);
	log->latency = request->latency;
	log->error_message = request->error_message;
}

#define LOG_FMT "\
%s\t\
START: %s\t\
END: %s\t\
PROTOCOL: %s\t\
NAME: %s\t\
URL: %s\t\
FREQUENCY: %d\t\
METHOD: %s\t\
TARGET_CODE: %s\t\
RESPONSE_CODE: %s\t\
RESPONSE_LENGTH: %d\t\
LATENCY: %f\t\
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
		log->frequency,
		log->method,
		log->target_code,
		log->response_code,
		log->response_length,
		log->latency,
		log->error_message);
}

static void	cleanup_log(t_log *log)
{
	free(log->start);
	free(log->end);
}

void	log_https_request(t_request *request)
{
	t_log	log;

	initialize_log(&log, request);
	write_log(&log);
	cleanup_log(&log);
}

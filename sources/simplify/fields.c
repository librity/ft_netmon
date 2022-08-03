/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:39:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 13:46:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*extract_value(char **fields, int index)
{
	char	*field;
	char	*value;

	field = *(fields + index);
	value = ft_strnstr(field, ": ", ft_strlen(field));
	if (value != NULL)
		value += 2;
	return (value);
}

static void	simplify_error(char **fields)
{
	t_req_error	req_error;

	req_error.time = extract_value(fields, LOG_END_INDEX);
	req_error.name = extract_value(fields, LOG_NAME_INDEX);
	req_error.address = extract_value(fields, LOG_ADDRESS_INDEX);
	req_error.protocol = extract_value(fields, LOG_PROTOCOL_INDEX);
	req_error.error_message = extract_value(fields, LOG_ERROR_MESSAGE_INDEX);
	put_request_error(req_error);
}

static void	simplify_success(char **fields)
{
	t_req_success	req_success;

	req_success.time = extract_value(fields, LOG_END_INDEX);
	req_success.protocol = extract_value(fields, LOG_PROTOCOL_INDEX);
	req_success.name = extract_value(fields, LOG_NAME_INDEX);
	req_success.address = extract_value(fields, LOG_ADDRESS_INDEX);
	req_success.latency = ft_atof(extract_value(fields, LOG_LATENCY_INDEX));
	put_request_success(req_success);
}

void	simplify_fields(char **fields)
{
	char	*type;

	type = *(fields + LOG_TYPE_INDEX);
	if (ft_streq(type, LOG_ERROR))
		simplify_error(fields);
	else
		simplify_success(fields);
	ft_free_strarr(fields);
}

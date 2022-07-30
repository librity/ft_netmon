/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 23:30:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	validate_field_count(char **fields)
{
	if (ft_strarr_len(fields) != HTTP_FIELD_COUNT)
		free_arr_and_die(fields, HTTP_FIELD_COUNT_ERR);
}

static void	validate_method(char **fields)
{
	char	*method;

	method = get_field(HTTP, fields, HTTP_METHOD_INDEX);
	if (!is_http_method(method))
		free_arr_and_die(fields, HTTP_METHOD_ERR);
}

static void	validate_code(char **fields)
{
	char	*code;

	code = get_field(HTTP, fields, HTTP_CODE_INDEX);
	if (!is_http_code(code))
		free_arr_and_die(fields, HTTP_CODE_ERR);
}

static void	validate_frequency(char **fields)
{
	char	*frequency;

	frequency = get_field(HTTP, fields, HTTP_FREQUENCY_INDEX);
	if (!is_valid_frequency(frequency))
		free_arr_and_die(fields, HTTP_FREQUENCY_ERR);
}

void	validate_http(char **fields)
{
	validate_field_count(fields);
	validate_method(fields);
	validate_code(fields);
	validate_frequency(fields);
}

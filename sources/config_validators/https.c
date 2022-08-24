/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   https.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	validate_field_count(char **fields)
{
	if (ft_strarr_len(fields) != HTTPS_FIELD_COUNT)
		free_arr_and_die(fields, HTTPS_FIELD_COUNT_ERR);
}

static void	validate_method(char **fields)
{
	char	*method;

	method = get_field(HTTPS, fields, HTTPS_METHOD_INDEX);
	if (!is_http_method(method))
		free_arr_and_die(fields, HTTPS_METHOD_ERR);
}

static void	validate_code(char **fields)
{
	char	*code;

	code = get_field(HTTPS, fields, HTTPS_CODE_INDEX);
	if (!is_http_code(code))
		free_arr_and_die(fields, HTTPS_CODE_ERR);
}

static void	validate_frequency(char **fields)
{
	char	*frequency;

	frequency = get_field(HTTPS, fields, HTTPS_FREQUENCY_INDEX);
	if (!is_valid_frequency(frequency))
		free_arr_and_die(fields, HTTPS_FREQUENCY_ERR);
}

void	validate_https(char **fields)
{
	validate_field_count(fields);
	validate_method(fields);
	validate_code(fields);
	validate_frequency(fields);
}

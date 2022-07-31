/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 13:13:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	parse_http(char **fields)
{
	int	frequency;

	frequency = atoi(get_field(HTTP, fields, HTTP_FREQUENCY_INDEX));
	add_http_target((t_new_http_target){
		.name = get_field(HTTP, fields, HTTP_NAME_INDEX),
		.address = get_field(HTTP, fields, HTTP_ADDRESS_INDEX),
		.method = get_field(HTTP, fields, HTTP_METHOD_INDEX),
		.code = get_field(HTTP, fields, HTTP_CODE_INDEX),
		.frequency = frequency
	});
}

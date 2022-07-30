/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 23:30:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	validate_field_count(char **fields)
{
	if (ft_strarr_len(fields) != PING_FIELD_COUNT)
		free_arr_and_die(fields, PING_FIELD_COUNT_ERR);
}

static void	validate_frequency(char **fields)
{
	char	*frequency;

	frequency = get_field(PING, fields, PING_FREQUENCY_INDEX);
	if (!is_valid_frequency(frequency))
		free_arr_and_die(fields, PING_FREQUENCY_ERR);
}

void	validate_ping(char **fields)
{
	validate_field_count(fields);
	validate_frequency(fields);
}

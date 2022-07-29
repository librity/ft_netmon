/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 20:51:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	validate_frequency(char *protocol, char **fields)
{
	char	*frequency;

	frequency = get_field(protocol, fields, HTTP_FREQUENCY_INDEX);
	if (!ft_str_is_uint(frequency))
		free_arr_and_die(fields, HTTP_FREQUENCY_ERR);
}

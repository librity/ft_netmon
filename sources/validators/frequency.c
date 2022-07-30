/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:28:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 23:31:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static bool	is_valid_string(char *str)
{
	if (ft_strlen(str) > FREQUENCY_FIELD_MAX_LENGTH)
		return (false);
	if (ft_is_plus_or_minus(*str))
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

bool	is_valid_frequency(char *str)
{
	long	number;

	if (!is_valid_string(str))
		return (false);
	number = ft_atol(str);
	if (number > UINT_MAX)
		return (false);
	if (number < 1)
		return (false);
	return (true);
}

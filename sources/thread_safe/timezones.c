/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timezones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:43:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 19:46:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	localtime_or_die(time_t *rawtime, t_timeinfo *timeinfo)
{
	void	*result;

	result = localtime_r(rawtime, timeinfo);
	if (result == NULL)
		die(LOCAL_TIME_CONVERT_ERR);
}

void	utctime_or_die(time_t *rawtime, t_timeinfo *timeinfo)
{
	void	*result;

	result = gmtime_r(rawtime, timeinfo);
	if (result == NULL)
		die(UTC_TIME_CONVERT_ERR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 21:35:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define LOGTIME_FMT "%Y-%m-%d %H:%M:%S"
#define LOGTIME_STRING_SIZE 20

static char	*logtime_or_die(t_timeinfo *timeinfo)
{
	char	*log_time;
	size_t	result;

	log_time = ft_salloc(LOGTIME_STRING_SIZE);
	result = strftime(log_time, LOGTIME_STRING_SIZE, LOGTIME_FMT, timeinfo);
	if (result == 0)
	{
		free(log_time);
		die(LOGTIME_CONVERT_ERR);
	}
	return (log_time);
}

/**
 * @brief Returns the current time in "Y-M-D h-m-s" format
 * as an allocated string. Thread safe.
 *
 * @return char * The allocated time string.
 */
char	*ts_logtime(void)
{
	time_t		rawtime;

	time(&rawtime);
	return (ts_raw_to_asctime(&rawtime));
}

/**
 * @brief Returns rawtime in "Y-M-D h-m-s" format as an allocated string.
 * Thread safe.
 *
 * @param rawtime Any pointer to a calendar time variable.
 * @return char * The allocated time string.
 */
char	*ts_raw_to_logtime(time_t *rawtime)
{
	t_timeinfo	localtime;
	char		*log_time;

	localtime_or_die(rawtime, &localtime);
	log_time = logtime_or_die(&localtime);
	return (log_time);
}

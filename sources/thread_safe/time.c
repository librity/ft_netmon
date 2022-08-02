/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 01:40:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	localtime_or_die(time_t *rawtime, t_timeinfo *timeinfo)
{
	void	*result;

	result = localtime_r(rawtime, timeinfo);
	if (result == NULL)
		die(RAWTIME_CONVERT_ERR);
}

static char	*asctime_or_die(t_timeinfo *timeinfo)
{
	char	*ascii_time;
	void	*result;

	ascii_time = ft_salloc(TIME_BUFFER_SIZE);
	result = asctime_r(timeinfo, ascii_time);
	if (result == NULL)
	{
		free(ascii_time);
		die(CALENDARTIME_CONVERT_ERR);
	}
	return (ascii_time);
}

static void	remove_endline(char *ascii_time)
{
	char	*endline;

	endline = ft_strchr(ascii_time, '\n');
	if (endline != NULL)
		*endline = '\0';
}

/**
 * @brief Returns the current time in human-readable format
 * as an allocated string. Thread safe.
 *
 * @return char * The allocated time string.
 */
char	*ts_asctime(void)
{
	time_t		rawtime;
	t_timeinfo	timeinfo;
	char		*ascii_time;

	time(&rawtime);
	localtime_or_die(&rawtime, &timeinfo);
	ascii_time = asctime_or_die(&timeinfo);
	remove_endline(ascii_time);
	return (ascii_time);
}

/**
 * @brief Returns rawtime in human-readable format as an allocated string.
 * Thread safe.
 *
 * @param rawtime Any pointer to a calendar time variable.
 * @return char * The allocated time string.
 */
char	*ts_raw_to_asctime(time_t *rawtime)
{
	t_timeinfo	timeinfo;
	char		*ascii_time;

	localtime_or_die(rawtime, &timeinfo);
	ascii_time = asctime_or_die(&timeinfo);
	remove_endline(ascii_time);
	return (ascii_time);
}

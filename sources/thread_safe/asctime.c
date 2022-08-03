/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asctime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 20:52:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*asctime_or_die(t_timeinfo *timeinfo)
{
	char	*ascii_time;
	void	*result;

	ascii_time = ft_salloc(ASCTIME_STRING_SIZE);
	result = asctime_r(timeinfo, ascii_time);
	if (result == NULL)
	{
		free(ascii_time);
		die(ASCTIME_CONVERT_ERR);
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

	time(&rawtime);
	return (ts_raw_to_asctime(&rawtime));
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
	t_timeinfo	localtime;
	char		*ascii_time;

	localtime_or_die(rawtime, &localtime);
	ascii_time = asctime_or_die(&localtime);
	remove_endline(ascii_time);
	return (ascii_time);
}

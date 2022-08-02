/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:45:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	localtime_or_die(time_t *rawtime, t_timeinfo *timeinfo)
{
	void		*result;

	result = localtime_r(rawtime, timeinfo);
	if (result == NULL)
		die("Can't convert rawtime to calendar time.");
}

static char	*asctime_or_die(t_timeinfo *timeinfo)
{
	char		*ascii_time;
	void		*result;

	ascii_time = ft_salloc(TIME_BUFFER_SIZE);
	result = asctime_r(timeinfo, ascii_time);
	if (result == NULL)
	{
		free(ascii_time);
		die("Can't convert calendar time to a human-readable string.");
	}
	return (ascii_time);
}

static void	remove_endline(char *ascii_time)
{
	char		*endline;

	endline = ft_strchr(ascii_time, '\n');
	if (endline != NULL)
		*endline = '\0';
}

char	*get_readable_time(void)
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

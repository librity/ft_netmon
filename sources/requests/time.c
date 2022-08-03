/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 03:25:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static double	clock_to_milliseconds(clock_t clock)
{
	return (((double)clock) * 1000 / CLOCKS_PER_SEC);
}

void	start_clock(t_request *request)
{
	request->clock = clock();
}

void	end_clock(t_request *request)
{
	clock_t	start;
	clock_t	end;

	end = clock();
	start = request->clock;
	request->clock = end - start;
	request->latency_msec = clock_to_milliseconds(request->clock);
}

void	end_time(t_request *request)
{
	time(&request->end);
}

void	start_time(t_request *request)
{
	time(&request->start);
}

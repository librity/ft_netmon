/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 00:18:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static double	clock_to_seconds(clock_t clock)
{
	return (((double)clock) / CLOCKS_PER_SEC);
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
	request->latency = clock_to_seconds(request->clock);
}

void	end_time(t_request *request)
{
	time(&request->end);
}

void	start_time(t_request *request)
{
	time(&request->start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:38:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

int	request_count(void)
{
	return (tpc()->request_count);
}

static void	set_request_count(int new_count)
{
	tpc()->request_count = new_count;
}

void	increase_request_count(void)
{
	if (request_count() > REQUEST_QUEUE_SIZE)
		die(REQUEST_COUNT_MAX_ERR);
	set_request_count(request_count() + 1);
	tdebug("Request count increased: %d", request_count());
}

void	decrease_request_count(void)
{
	if (request_count() <= 0)
		die(REQUEST_COUNT_MIN_ERR);
	set_request_count(request_count() - 1);
	tdebug("Request count decreased: %d", request_count());
}

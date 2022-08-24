/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_success.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define SUCCESS_FMT "\
\033[1;36m[\033[0;35m%s\033[1;36m] \
\033[1;32m%s (%s) on %s \033[0;32mis up (latency: %f ms).\n\
"

void	put_request_success(t_req_success req_success)
{
	ts_printf(SUCCESS_FMT RC,
		req_success.time,
		req_success.name,
		req_success.address,
		req_success.protocol,
		req_success.latency);
}

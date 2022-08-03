/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 13:13:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define ERROR_FMT "\
\033[1;36m[\033[0;35m%s\033[1;36m] \
\033[1;31m%s (%s) on %s \033[0;31mrequest error: \
\033[1;34m%s\n\
"

void	put_request_error(t_req_error req_error)
{
	ts_printf(ERROR_FMT RC,
		req_error.time,
		req_error.name,
		req_error.address,
		req_error.protocol,
		req_error.error_message);
}

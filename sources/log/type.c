/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:43 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

char	*resolve_log_type(t_request *request)
{
	if (request->error)
		return (LOG_ERROR);
	return (LOG_INFO);
}

char	*resolve_log_error(t_request *request)
{
	if (request->error)
		return (LOG_TRUE);
	return (LOG_FALSE);
}

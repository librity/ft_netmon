/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 00:30:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*handle_ping(t_request *request)
{
	t_ping	p;

	p.req = request;
	p.req = NULL;
	ping_prepare_address(&p);
	if (p.err != NULL)
		return (p.err);
	ping_prepare_socket(&p);
	if (p.err != NULL)
		return (p.err);
	ping_prepare_packet(&p.packet);
	ping_send_and_receive(&p);
	if (p.err != NULL)
		return (p.err);
	return (NULL);
}

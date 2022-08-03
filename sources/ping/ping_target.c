/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 12:22:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*ping_target(t_request *request)
{
	t_ping	p;

	p.req = request;
	prepare_address(&p);
	if (p.err != NULL)
		return (p.err);
	prepare_socket(&p);
	if (p.err != NULL)
		return (p.err);
	prepare_packet(&p.packet);
	ping_send_and_receive(&p);
	if (p.err != NULL)
		return (p.err);
	return (NULL);
}

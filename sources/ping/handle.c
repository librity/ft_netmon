/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 02:50:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	initialize_ping(t_ping *p, t_request *request)
{
	ft_bzero(p, sizeof(*p));
	p->req = request;
}

char	*handle_ping(t_request *request)
{
	t_ping	p;

	initialize_ping(&p, request);
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

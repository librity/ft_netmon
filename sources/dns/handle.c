/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	initialize_dns(t_dns *d, t_request *request)
{
	ft_bzero(d, sizeof(*d));
	d->req = request;
}

char	*handle_dns(t_request *request)
{
	t_dns	d;

	initialize_dns(&d, request);
	dns_prepare_query(&d);
	dns_prepare_address(&d);
	dns_send_and_receive(&d);
	if (d.err != NULL)
		return (d.err);
	dns_extract_ip(&d);
	if (d.err != NULL)
		return (d.err);
	return (NULL);
}

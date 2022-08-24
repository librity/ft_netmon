/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	validate_fields(char **fields)
{
	char	*protocol;

	protocol = get_protocol(fields);
	if (ft_streq(protocol, HTTP))
		return (validate_http(fields));
	if (ft_streq(protocol, HTTPS))
		return (validate_https(fields));
	if (ft_streq(protocol, PING))
		return (validate_ping(fields));
	if (ft_streq(protocol, DNS))
		return (validate_dns(fields));
	free_arr_and_die(fields, CONFIG_PROTOCOL_ERR);
}

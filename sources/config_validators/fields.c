/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 00:01:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	validate_fields(char **fields)
{
	char	*protocol;

	protocol = get_protocol(fields);
	if (ft_streq(protocol, HTTP))
		return (validate_http(fields));
	if (ft_streq(protocol, PING))
		return (validate_ping(fields));
	if (ft_streq(protocol, DNS))
		return (validate_dns(fields));
	free_arr_and_die(fields, CONFIG_PROTOCOL_ERR);
}

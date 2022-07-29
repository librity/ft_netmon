/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 02:20:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	validate_dns(char **fields)
{
	fields = fields;
}

static void	validate_ping(char **fields)
{
	fields = fields;
}

static void	validate_http(char **fields)
{
	fields = fields;
}

void	validate_fields_or_die(char **fields)
{
	char	*protocol;

	protocol = *(fields + 1);
	if (ft_streq(protocol, HTTP_IDENTIFIER))
		return (validate_http(fields));
	if (ft_streq(protocol, PING_IDENTIFIER))
		return (validate_ping(fields));
	if (ft_streq(protocol, DNS_IDENTIFIER))
		return (validate_dns(fields));
	free_strings_and_die(fields, CONFIG_PROTOCOL_ERR);
}

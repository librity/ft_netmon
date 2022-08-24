/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	parse_dns(char **fields)
{
	int	frequency;

	frequency = atoi(get_field(DNS, fields, DNS_FREQUENCY_INDEX));
	add_dns_target((t_new_dns_target){
		.name = get_field(DNS, fields, DNS_NAME_INDEX),
		.address = get_field(DNS, fields, DNS_ADDRESS_INDEX),
		.frequency = frequency,
		.dns_ipv4 = get_field(DNS, fields, DNS_SERVER_IPV4_INDEX)
	});
}

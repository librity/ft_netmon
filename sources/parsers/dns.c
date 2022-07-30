/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 16:43:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	parse_dns(char **fields)
{
	int	frequency;

	frequency = atoi(get_field(DNS, fields, DNS_FREQUENCY_INDEX));
	add_dns_target((t_new_dns_target){
		get_field(DNS, fields, DNS_NAME_INDEX),
		get_field(DNS, fields, DNS_ADDRESS_INDEX),
		frequency,
		get_field(DNS, fields, DNS_SERVER_IPV4_INDEX)
	});
}

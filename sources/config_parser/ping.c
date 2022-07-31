/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 21:23:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	parse_ping(char **fields)
{
	int	frequency;

	frequency = atoi(get_field(PING, fields, PING_FREQUENCY_INDEX));
	add_ping_target((t_new_ping_target){
		.name = get_field(PING, fields, PING_NAME_INDEX),
		.address = get_field(PING, fields, PING_ADDRESS_INDEX),
		.frequency = frequency
	});
}

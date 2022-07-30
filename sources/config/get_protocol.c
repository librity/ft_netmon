/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_protocol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 00:01:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

char	*get_protocol(char **fields)
{
	return (extract_field(fields, PROTOCOL_INDEX));
}

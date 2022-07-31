/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:31:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 13:09:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	**protocols(void)
{
	static char	*__protocols[] = {HTTP, PING, DNS, NULL};

	return (__protocols);
}

bool	is_valid_protocol(char *field)
{
	return (ft_str_in_strarr(protocols(), field));
}

char	*get_protocol_by_code(t_protocol code)
{
	if (code == HTTP_CODE)
		return (HTTP);
	if (code == PING_CODE)
		return (PING);
	if (code == DNS_CODE)
		return (DNS);
	return (NULL);
}

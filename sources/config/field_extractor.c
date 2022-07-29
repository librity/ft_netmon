/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_extractor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 20:51:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static int	resolve_field_count(char *protocol)
{
	if (ft_streq(protocol, HTTP))
		return (HTTP_FIELD_COUNT);
	if (ft_streq(protocol, PING))
		return (PING_FIELD_COUNT);
	if (ft_streq(protocol, DNS))
		return (DNS_FIELD_COUNT);
	return (ARRAY_BAD_INDEX_CODE);
}

char	*extract_field(char **fields, int index)
{
	return (*(fields + index));
}

char	*get_field(char *protocol, char **fields, int index)
{
	int	field_count;

	if (!is_valid_protocol(protocol))
		return (NULL);
	if (index < 0)
		return (NULL);
	field_count = resolve_field_count(protocol);
	if (field_count == ARRAY_BAD_INDEX_CODE)
		return (NULL);
	if (index > field_count)
		return (NULL);
	return (extract_field(fields, index));
}

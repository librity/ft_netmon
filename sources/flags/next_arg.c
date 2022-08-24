/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:35:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

bool	next_is_flag(char **arguments)
{
	char	*next;

	next = *(arguments + 1);
	if (next == NULL)
		return (false);
	if (is_bool_flag(next))
		return (true);
	if (is_file_flag(next))
		return (true);
	if (is_int_flag(next))
		return (true);
	return (false);
}

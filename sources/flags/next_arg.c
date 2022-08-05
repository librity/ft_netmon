/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:35:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 14:57:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

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

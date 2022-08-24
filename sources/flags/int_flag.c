/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 14:57:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	**int_flags(void)
{
	static char	*__int_flags[] = {
		WORKERS_FLAG, WORKERS_FLAG_SHORT, NULL
	};

	return (__int_flags);
}

static void	set_int_flag(char **arguments)
{
	char	*ascii_int;
	int		value;

	ascii_int = *(arguments + 1);
	if (ascii_int == NULL)
		die(INT_FLAG_ARGUMENT_ERR);
	value = ft_atoi(ascii_int);
	if (ft_streq(*arguments, WORKERS_FLAG))
		return (set_workers_count(value));
	if (ft_streq(*arguments, WORKERS_FLAG_SHORT))
		return (set_workers_count(value));
}

bool	is_int_flag(char *argument)
{
	return (ft_str_in_strarr(int_flags(), argument));
}

bool	handled_int_flag(char **arguments)
{
	if (!is_int_flag(*arguments))
		return (false);
	if (next_is_flag(arguments))
		return (false);
	set_int_flag(arguments);
	return (true);
}

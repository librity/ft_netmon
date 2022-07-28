/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 18:59:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	**simple_flags(void)
{
	static char	*__simple_flags[] = {
		HELP_FLAG_1, HELP_FLAG_2, SIMPLIFY_FLAG, NULL
	};

	return (__simple_flags);
}

void	set_simple_flag(char *flag)
{
	if (ft_streq(flag, HELP_FLAG_1))
		return (activate_help_flag());
	if (ft_streq(flag, HELP_FLAG_2))
		return (activate_help_flag());
	if (ft_streq(flag, SIMPLIFY_FLAG))
		return (activate_simplify_flag());
}

bool	is_simple_flag(char *argument)
{
	char	**flag;

	flag = simple_flags();
	while (*flag != NULL)
	{
		if (ft_streq(argument, *flag))
			return (true);
		flag++;
	}
	return (false);
}

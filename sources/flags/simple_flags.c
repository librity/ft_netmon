/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 22:33:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	**simple_flags(void)
{
	static char	*__simple_flags[] = {
		HELP_FLAG, HELP_FLAG_SHORT, SIMPLIFY_FLAG, SIMPLIFY_FLAG_SHORT, NULL
	};

	return (__simple_flags);
}

void	set_simple_flags(char *flag)
{
	if (ft_streq(flag, HELP_FLAG_SHORT))
		return (activate_help_flag());
	if (ft_streq(flag, HELP_FLAG))
		return (activate_help_flag());
	if (ft_streq(flag, SIMPLIFY_FLAG))
		return (activate_simplify_flag());
	if (ft_streq(flag, SIMPLIFY_FLAG_SHORT))
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

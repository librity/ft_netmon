/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 17:08:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	**bool_flags(void)
{
	static char	*__bool_flags[] = {
		HELP_FLAG, HELP_FLAG_SHORT,
		SIMPLIFY_FLAG, SIMPLIFY_FLAG_SHORT,
		DEBUG_FLAG, DEBUG_FLAG_SHORT,
		NULL
	};

	return (__bool_flags);
}

void	set_bool_flags(char *flag)
{
	if (ft_streq(flag, HELP_FLAG_SHORT))
		return (enable_help_flag());
	if (ft_streq(flag, HELP_FLAG))
		return (enable_help_flag());
	if (ft_streq(flag, SIMPLIFY_FLAG))
		return (enable_simplify_flag());
	if (ft_streq(flag, SIMPLIFY_FLAG_SHORT))
		return (enable_simplify_flag());
	if (ft_streq(flag, DEBUG_FLAG))
		return (enable_debug_flag());
	if (ft_streq(flag, DEBUG_FLAG_SHORT))
		return (enable_debug_flag());
}

bool	is_bool_flag(char *argument)
{
	return (ft_str_in_strarr(bool_flags(), argument));
}

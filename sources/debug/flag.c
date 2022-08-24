/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	debug_bool_flag(char *flag_name, bool flag)
{
	if (flag)
		ft_bdebug(debug(), "Is %s flag enabled? YES", flag_name);
	else
		ft_bdebug(debug(), "Is %s flag enabled? NO", flag_name);
}

void	debug_file_flag(char *flag_name, char *file_path)
{
	ft_bdebug(debug(), "%s path: %s", flag_name, file_path);
}

void	debug_int_flag(char *flag_name, int number)
{
	ft_bdebug(debug(), "%s: %d", flag_name, number);
}

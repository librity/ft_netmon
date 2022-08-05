/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 15:11:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	parse_flags(void)
{
	char	**arguments;

	arguments = argv() + 1;
	while (*arguments != NULL)
	{
		if (handled_bool_flag(*arguments))
		{
			arguments++;
			continue ;
		}
		if (handled_file_flag(arguments))
		{
			arguments = arguments + 2;
			continue ;
		}
		if (handled_int_flag(arguments))
		{
			arguments = arguments + 2;
			continue ;
		}
		die(BAD_FLAGS_ERR);
	}
}

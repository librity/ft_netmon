/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 17:07:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	parse_flags(void)
{
	char	**arguments;

	arguments = argv() + 1;
	while (*arguments != NULL)
	{
		if (is_bool_flag(*arguments))
			set_bool_flags(*arguments);
		if (is_file_flag(*arguments))
		{
			set_file_flags(arguments);
			arguments++;
		}
		arguments++;
	}
}

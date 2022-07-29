/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 22:23:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	validate_flags(void)
{
	if (ft_streq(log_path(), config_path()))
		die(EQUAL_FILE_PATHS_ERR);
}

void	handle_flags(void)
{
	parse_flags();
	validate_flags();
	if (help_flag())
		help_and_quit();
	if (simplify_flag())
		simplify_and_quit();
}

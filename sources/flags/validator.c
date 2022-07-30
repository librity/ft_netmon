/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:04:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 18:05:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	validate_flags(void)
{
	if (ft_streq(log_path(), config_path()))
		die(EQUAL_FILE_PATHS_ERR);
}

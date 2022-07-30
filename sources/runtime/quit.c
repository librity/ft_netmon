/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:35:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 17:49:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	quit(void)
{
	close_files();
	free_memory();
	exit(EXIT_SUCCESS);
}

void	help_and_quit(void)
{
	ft_putstr(HELP_MSG);
	quit();
}

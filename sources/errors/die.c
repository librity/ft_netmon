/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 01:10:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	die(char *error_message)
{
	close_files();
	free_memory();
	ft_die(error_message);
}

void	free_and_die(void *free_me, char *error_message)
{
	free(free_me);
	die(error_message);
}

void	free_strings_and_die(char **free_me, char *error_message)
{
	ft_free_string_array(free_me);
	die(error_message);
}

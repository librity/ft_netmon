/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	die(char *error_message)
{
	print_error(error_message);
	exit(EXIT_FAILURE);
}

void	free_and_die(void *free_me, char *error_message)
{
	free(free_me);
	die(error_message);
}

void	free_arr_and_die(char **free_me, char *error_message)
{
	ft_free_strarr(free_me);
	die(error_message);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

#define ERROR_PREFIX "ERROR:\t"

void	print_error(char *message)
{
	ts_fprintf(stderr, RB ERROR_PREFIX "%s%s\n" RC, R, message);
}

#define WARNING_PREFIX "WRNNG:\t"

void	print_warning(char *message)
{
	ts_fprintf(stderr, YB WARNING_PREFIX "%s%s\n" RC, Y, message);
}

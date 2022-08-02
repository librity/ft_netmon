/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 13:53:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

#define ERROR_PREFIX "ERROR:\t"

void	print_error(char *message)
{
	ts_fprintf(stderr, RB ERROR_PREFIX "%s%s\n" RC, R, message);
}

#define WARNING_PREFIX "WARNG:\t"

void	print_warning(char *message)
{
	ts_fprintf(stderr, YB WARNING_PREFIX "%s%s\n" RC, Y, message);
}

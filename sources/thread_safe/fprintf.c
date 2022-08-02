/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 22:28:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

/*
** Behaves exactly like fprintf but with flockfile/funlockfile
** so it's thread safe.
*/
void	ts_fprintf(FILE *filehandle, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	flockfile(filehandle);
	vfprintf(filehandle, format, ap);
	funlockfile(filehandle);
	va_end(ap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 12:04:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

/**
 * @brief Behaves exactly like fprintf but with flockfile/funlockfile
 * so it's thread safe.
 *
 * @param filehandle File stream where output will be written.
 * @param format Formate string with specifiers and flags like %.5s and %4.2f.
 * @param ... Variadic elements that will be inserted in each specifier.
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

/**
 * @brief Behaves exactly like printf but with flockfile/funlockfile
 * so it's thread safe.
 *
 * @param format Formate string with specifiers and flags like %.5s and %4.2f.
 * @param ... Variadic elements that will be inserted in each specifier.
 */
void	ts_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	flockfile(stdout);
	vfprintf(stdout, format, ap);
	funlockfile(stdout);
	va_end(ap);
}

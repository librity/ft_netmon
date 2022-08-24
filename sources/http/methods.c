/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:31:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	**http_methods(void)
{
	static char	*__http_methods[] = {
		HTTP_METHOD_GET, HTTP_METHOD_HEAD, HTTP_METHOD_POST, HTTP_METHOD_PUT,
		HTTP_METHOD_DELETE, HTTP_METHOD_CONNECT, HTTP_METHOD_OPTIONS,
		HTTP_METHOD_TRACE, HTTP_METHOD_PATCH, NULL};

	return (__http_methods);
}

bool	is_http_method(char *field)
{
	return (ft_str_in_strarr(http_methods(), field));
}

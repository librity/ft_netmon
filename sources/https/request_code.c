/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:31:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	set_request_code(t_request *request, CURL *curl)
{
	long	response_code;

	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
	request->code = get_http_code_string(response_code);
}

bool	has_expected_code(t_request *request)
{
	if (request->code == NULL)
		return (false);
	if (!ft_streq(request->code, request->target->code))
		return (false);
	return (true);
}

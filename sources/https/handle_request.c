/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 01:50:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	set_curl_options(CURL *curl, t_request *request)
{
	curl_easy_setopt(curl, CURLOPT_URL, request->url);
}

static t_request	*initialize_request(t_target *target)
{
	t_request	*request;

	request = new_request(target);
	request->url = ft_strjoin(HTTPS_URL_PREFIX, request->target->address.name);
	return (request);
}

void	handle_https_request(t_target *target)
{
	t_request	*request;
	CURL		*curl;

	request = initialize_request(target);
	curl = curl_easy_init();
	if (curl == NULL)
		return (handle_request_error(request, CURL_INIT_ERR));
	set_curl_options(curl, request);
	start_clock(request);
	request->curl_code = curl_easy_perform(curl);
	end_clock(request);
	if (request->curl_code != CURLE_OK)
		return (handle_request_error(request,
				(char *)curl_easy_strerror(request->curl_code)));
	curl_easy_cleanup(curl);
	handle_request_success(request);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl_request.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:37:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static size_t	curl_writer(void *data, size_t size, size_t nmemb,
		void *response_vp)
{
	t_lstr	*response;

	response = response_vp;
	ft_join_lstr_str(response, data, size * nmemb);
	return (size * nmemb);
}

static void	set_curl_options(t_request *request, CURL *curl)
{
	curl_easy_setopt(curl, CURLOPT_URL, request->url);
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request->target->method);
	curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &request->response);
}

static void	send_request(t_request *request, CURL *curl)
{
	start_clock(request);
	request->curl_code = curl_easy_perform(curl);
	end_clock(request);
}

static char	*get_curl_error(t_request *request)
{
	return ((char *)curl_easy_strerror(request->curl_code));
}

char	*handle_curl_request(t_request *request)
{
	CURL	*curl;

	curl = curl_easy_init();
	if (curl == NULL)
		return (CURL_INIT_ERR);
	set_curl_options(request, curl);
	send_request(request, curl);
	set_request_code(request, curl);
	curl_easy_cleanup(curl);
	if (request->curl_code != CURLE_OK)
		return (get_curl_error(request));
	if (!has_expected_code(request))
		return (HTTPS_BAD_CODE);
	return (NULL);
}

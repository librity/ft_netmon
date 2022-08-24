/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

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

static CURLcode	send_request(t_request *request, CURL *curl)
{
	CURLcode	curl_code;

	start_clock(request);
	curl_code = curl_easy_perform(curl);
	stop_clock(request);
	return (curl_code);
}

static char	*get_curl_error(CURLcode curl_code)
{
	return ((char *)curl_easy_strerror(curl_code));
}

char	*handle_curl(t_request *request)
{
	CURL		*curl;
	CURLcode	curl_code;

	curl = curl_easy_init();
	if (curl == NULL)
		return (CURL_INIT_ERR);
	set_curl_options(request, curl);
	curl_code = send_request(request, curl);
	set_request_code(request, curl);
	curl_easy_cleanup(curl);
	if (curl_code != CURLE_OK)
		return (get_curl_error(curl_code));
	if (!has_expected_code(request))
		return (HTTPS_EXPECTED_CODE_ERR);
	return (NULL);
}

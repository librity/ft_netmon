/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 02:48:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static char	*set_header_tokens(t_http *h)
{
	char	*line_end;

	line_end = ft_strnstr(h->req->response.ptr, HTTP_DELIMITER,
			ft_strlen(h->req->response.ptr));
	if (line_end == NULL)
		return (HTTP_HEADER_ERR);
	h->header_tokens = ft_split(h->req->response.ptr, ' ');
	if (h->header_tokens == NULL)
		return (HTTP_HEADER_ERR);
	if (ft_strarr_len(h->header_tokens) < 2)
	{
		ft_free_strarr(h->header_tokens);
		return (HTTP_HEADER_ERR);
	}
	return (NULL);
}

static char	*validate_http_code(t_http *h)
{
	char	*code;
	char	*target_code;

	code = *(h->header_tokens + 1);
	target_code = h->req->target->code;
	if (!ft_streq(code, target_code))
		return (HTTP_EXPECTED_CODE_ERR);
	return (NULL);
}

void	http_validate_response(t_http *h)
{
	h->err = set_header_tokens(h);
	if (h->err != NULL)
		return ;
	h->err = validate_http_code(h);
	ft_free_strarr(h->header_tokens);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:31:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static char	**http_codes(void)
{
	static char	*__http_codes[] = {
		HTTP_CODE_100, HTTP_CODE_101, HTTP_CODE_102, HTTP_CODE_103,
		HTTP_CODE_200, HTTP_CODE_201, HTTP_CODE_202, HTTP_CODE_203,
		HTTP_CODE_204, HTTP_CODE_205, HTTP_CODE_206, HTTP_CODE_207,
		HTTP_CODE_208, HTTP_CODE_226, HTTP_CODE_300, HTTP_CODE_301,
		HTTP_CODE_302, HTTP_CODE_303, HTTP_CODE_304, HTTP_CODE_305,
		HTTP_CODE_306, HTTP_CODE_307, HTTP_CODE_308, HTTP_CODE_400,
		HTTP_CODE_401, HTTP_CODE_402, HTTP_CODE_403, HTTP_CODE_404,
		HTTP_CODE_405, HTTP_CODE_406, HTTP_CODE_407, HTTP_CODE_408,
		HTTP_CODE_409, HTTP_CODE_410, HTTP_CODE_411, HTTP_CODE_412,
		HTTP_CODE_413, HTTP_CODE_414, HTTP_CODE_415, HTTP_CODE_416,
		HTTP_CODE_417, HTTP_CODE_418, HTTP_CODE_421, HTTP_CODE_422,
		HTTP_CODE_423, HTTP_CODE_424, HTTP_CODE_425, HTTP_CODE_426,
		HTTP_CODE_428, HTTP_CODE_429, HTTP_CODE_431, HTTP_CODE_451,
		HTTP_CODE_500, HTTP_CODE_501, HTTP_CODE_502, HTTP_CODE_503,
		HTTP_CODE_504, HTTP_CODE_505, HTTP_CODE_506, HTTP_CODE_507,
		HTTP_CODE_508, HTTP_CODE_510, HTTP_CODE_511, NULL};

	return (__http_codes);
}

bool	is_http_code(char *field)
{
	return (ft_str_in_strarr(http_codes(), field));
}

char	*get_http_code_string(long code_number)
{
	char	*code_string;
	char	*arr_string;

	code_string = ft_ltoa(code_number);
	arr_string = ft_find_in_strarr(http_codes(), code_string);
	free(code_string);
	return (arr_string);
}

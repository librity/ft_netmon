/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

bool	has_expected_code(t_request *request)
{
	if (request->code == NULL)
		return (false);
	if (!ft_streq(request->code, request->target->code))
		return (false);
	return (true);
}

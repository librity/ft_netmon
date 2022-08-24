/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

bool	simplify_flag(void)
{
	return (c()->simplify_flag);
}

void	enable_simplify_flag(void)
{
	c()->simplify_flag = true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

t_dlist	**targets(void)
{
	return (&(c()->targets));
}

int	targets_count(void)
{
	return (ft_dlstsize(*targets()));
}

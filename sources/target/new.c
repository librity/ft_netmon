/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

t_target	*new_target(void)
{
	t_target	*new;

	new = ft_lalloc(lalloc(), sizeof(t_target));
	ft_bzero(new, sizeof(t_target));
	ft_bzero(&new->address, sizeof(t_address));
	ft_bzero(&new->dns, sizeof(t_address));
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 16:44:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static t_ping_target	*new_ping_target(t_new_ping_target p)
{
	t_ping_target	*new;

	new = (t_ping_target *)ft_lalloc(lalloc(), sizeof(t_ping_target));
	new->name = ft_strdup_lalloc(lalloc(), p.name);
	new->address.name = ft_strdup_lalloc(lalloc(), p.address_name);
	new->frequency = p.frequency;
	return (new);
}

void	add_ping_target(t_new_ping_target p)
{
	t_ping_target	*ping_target;

	ping_target = new_ping_target(p);
	ft_dlst_add_lalloc(lalloc(), ping_targets(), ping_target);
}

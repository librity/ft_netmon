/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 12:58:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static t_target	*new_dns_target(t_new_dns_target p)
{
	t_target	*new;

	new = new_target();
	new->protocol = DNS_CODE;
	new->name = ft_strdup_lalloc(lalloc(), p.name);
	new->address.name = ft_strdup_lalloc(lalloc(), p.address);
	new->frequency = p.frequency;
	new->dns.ipv4 = ft_strdup_lalloc(lalloc(), p.dns_ipv4);
	return (new);
}

void	add_dns_target(t_new_dns_target p)
{
	t_target	*dns_target;

	dns_target = new_dns_target(p);
	ft_dlst_add_lalloc(lalloc(), targets(), dns_target);
}

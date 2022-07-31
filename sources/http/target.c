/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/31 13:02:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static t_target	*new_http_target(t_new_http_target p)
{
	t_target	*new;

	new = new_target();
	new->protocol = HTTP_CODE;
	new->name = ft_strdup_lalloc(lalloc(), p.name);
	new->address.name = ft_strdup_lalloc(lalloc(), p.address);
	new->method = ft_strdup_lalloc(lalloc(), p.method);
	new->code = ft_strdup_lalloc(lalloc(), p.code);
	new->frequency = p.frequency;
	return (new);
}

void	add_http_target(t_new_http_target p)
{
	t_target	*http_target;

	http_target = new_http_target(p);
	ft_dlst_add_lalloc(lalloc(), targets(), http_target);
}

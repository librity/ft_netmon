/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 20:39:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

t_thread	*new_thread(void)
{
	t_thread	*new;

	new = ft_lalloc(lalloc(), sizeof(t_thread));
	ft_bzero(new, sizeof(t_thread));
	return (new);
}

void	add_thread(t_dlist **threads)
{
	t_thread	*http_thret_thread;

	http_thret_thread = new_thread();
	ft_dlst_add_lalloc(lalloc(), threads, http_thret_thread);
}

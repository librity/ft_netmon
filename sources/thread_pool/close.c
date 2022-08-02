/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:35:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	destroy_locks(void)
{
	destroy_mutex(queue_mutex());
	destroy_cond(queue_cond());
}

void	close_thread_pool(void)
{
	cancel_schedulers();
	cancel_workers();
	join_schedulers();
	join_workers();
	destroy_locks();
}

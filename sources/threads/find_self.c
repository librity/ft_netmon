/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_self.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

t_thread	*find_self(void)
{
	return (find_thread(pthread_self()));
}

t_thread	*find_self_or_tdie(void)
{
	t_thread	*thread;

	thread = find_self();
	if (thread == NULL)
		tdie(THRD_FIND_ERR);
	return (thread);
}

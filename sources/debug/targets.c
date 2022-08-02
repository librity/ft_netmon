/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 20:52:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	debug_target_count(void)
{
	ft_bdebug(debug(), "Total targets: %d", targets_count());
}

void	debug_targets(void)
{
	debug_target_count();
	ft_bdebug(debug(), "TARGETS:");
	ft_dlstiter(*targets(), &inspect_target);
}

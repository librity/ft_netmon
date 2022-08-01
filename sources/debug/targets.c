/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:45:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	debug_target_count(t_dlist **targets)
{
	ft_bdebug(debug(), "Total targets: %d", ft_dlstsize(*targets));
}

void	debug_targets(void)
{
	debug_target_count(targets());
	ft_bdebug(debug(), "TARGETS:");
	ft_dlstiter(*targets(), &inspect_target);
}

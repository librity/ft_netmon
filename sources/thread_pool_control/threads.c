/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 14:17:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

t_dlist	**workers(void)
{
	return (&(tpc()->workers));
}

int	count_workers(void)
{
	return (ft_dlstsize(*workers()));
}

t_dlist	**schedulers(void)
{
	return (&(tpc()->schedulers));
}

int	count_schedulers(void)
{
	return (ft_dlstsize(*schedulers()));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

void	tdie(char *error_message)
{
	fprintf(stderr, "Exiting thread %lu: %s\n", pthread_self(), error_message);
	pthread_exit(NULL);
}

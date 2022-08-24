/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:14:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:40:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	check_raw_sockets_capability(void)
{
	if (!can_use_raw_sockets())
		die(RAW_SOCKET_CAP_ERR);
}

static void	print_banner(void)
{
	ft_clear();
	ft_putendl(WELCOME_BANNER);
}

void	handle_monitoring(void)
{
	check_raw_sockets_capability();
	enable_tty_raw_mode();
	print_banner();
	handle_config();
	open_log_fs();
	initialize_thread_pool();
}

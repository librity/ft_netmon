/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 16:51:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	initialize(int argc, char **argv)
{
	initialize_control(argc, argv);
	handle_flags();
	handle_config();
}

void	run_log(void)
{
	ft_debug("http_targets = %d", ft_dlstsize(*http_targets()));
	ft_debug("ping_targets = %d", ft_dlstsize(*ping_targets()));
	ft_debug("dns_targets = %d", ft_dlstsize(*dns_targets()));
}

void	cleanup(void)
{
	close_files();
	free_memory();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run_log();
	cleanup();
	return (EXIT_SUCCESS);
}

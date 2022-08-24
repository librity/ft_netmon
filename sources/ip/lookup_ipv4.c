/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_ipv4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:09:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	extract_ip_string(t_addrinfo *info, char *address)
{
	void	*aux;

	inet_ntop(info->ai_family, info->ai_addr->sa_data, address,
		IPV4_ADDRESS_STRING_SIZE);
	aux = &((t_inet_sockaddr *)info->ai_addr)->sin_addr;
	inet_ntop(info->ai_family, aux, address, IPV4_ADDRESS_STRING_SIZE);
}

static void	set_options(t_addrinfo *options)
{
	ft_bzero(options, sizeof(t_addrinfo));
	options->ai_family = AF_INET;
	options->ai_flags |= AI_CANONNAME;
}

char	*lookup_ipv4(char *name)
{
	t_addrinfo	options;
	t_addrinfo	*info;
	int			result;
	char		*address;

	set_options(&options);
	result = getaddrinfo(name, NULL, &options, &info);
	if (result != 0)
		return (NULL);
	address = ft_salloc(IPV4_ADDRESS_STRING_SIZE);
	extract_ip_string(info, address);
	freeaddrinfo(info);
	return (address);
}

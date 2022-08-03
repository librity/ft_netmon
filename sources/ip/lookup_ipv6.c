/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_ipv6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:09:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 01:58:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	extract_ip_string(t_addrinfo *info, char *address)
{
	void	*aux;

	inet_ntop(info->ai_family, info->ai_addr->sa_data, address,
		IPV6_ADDRESS_STRING_SIZE);
	aux = &((t_inet6_sockaddr *)info->ai_addr)->sin6_addr;
	inet_ntop(info->ai_family, aux, address, IPV6_ADDRESS_STRING_SIZE);
}

static void	set_options(t_addrinfo *options)
{
	ft_bzero(options, sizeof(t_addrinfo));
	options->ai_family = AF_INET6;
	options->ai_flags |= AI_CANONNAME;
}

char	*lookup_ipv6(char *name)
{
	t_addrinfo	options;
	t_addrinfo	*info;
	int			result;
	char		*address;

	set_options(&options);
	result = getaddrinfo(name, NULL, &options, &info);
	if (result != 0)
		return (NULL);
	address = ft_salloc(IPV6_ADDRESS_STRING_SIZE);
	extract_ip_string(info, address);
	freeaddrinfo(info);
	return (address);
}

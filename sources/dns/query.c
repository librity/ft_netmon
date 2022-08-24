/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:31:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:37:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netmon.h>

static void	write_header(t_dns *d)
{
	const unsigned char	header[] = {
		0xDB, 0x42, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	d->query.length = 12;
	ft_memcpy(d->query.message, header, d->query.length);
}

static void	write_word(t_dns *d, char *word)
{
	size_t	word_length;

	word_length = ft_strlen(word);
	d->query.message[d->query.length++] = word_length;
	ft_memcpy(d->query.message + d->query.length, word, word_length);
	d->query.length += word_length;
}

#define END_OF_HOSTNAME 0x00

static void	write_domain_name(t_dns *d)
{
	char	**free_me;
	char	**words;

	words = ft_split(d->req->target->address.name, '.');
	free_me = words;
	while (*words != NULL)
	{
		write_word(d, *words);
		words++;
	}
	d->query.message[d->query.length++] = END_OF_HOSTNAME;
	ft_free_strarr(free_me);
}

#define A_TYPE_QUERY 0x00
#define TYPE_QUERY 0x01
#define INTERNET_ADDRESS_TYPE_QUERY 0x00
#define END_OF_QUERY 0x01

static void	write_footer(t_dns *d)
{
	d->query.message[d->query.length++] = A_TYPE_QUERY;
	d->query.message[d->query.length++] = TYPE_QUERY;
	d->query.message[d->query.length++] = INTERNET_ADDRESS_TYPE_QUERY;
	d->query.message[d->query.length++] = END_OF_QUERY;
}

void	dns_prepare_query(t_dns *d)
{
	write_header(d);
	write_domain_name(d);
	write_footer(d);
}

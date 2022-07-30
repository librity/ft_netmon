/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 16:52:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>

/******************************************************************************\
 * FILES
\******************************************************************************/

typedef struct s_file
{
	char		*path;
	int			fd;
}				t_file;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_control
{
	int			argc;
	char		**argv;

	bool		help_flag;
	bool		simplify_flag;
	bool		debug_flag;

	t_file		config;
	t_file		log;

	t_dlist		*http_targets;
	t_dlist		*ping_targets;
	t_dlist		*dns_targets;

	t_list		*lalloc;
}				t_control;

/******************************************************************************\
 * NETWORK
\******************************************************************************/

typedef struct s_address
{
	char		*name;
	char		*ipv4;
	char		*ipv6;
}				t_address;

/******************************************************************************\
 * HTTP
\******************************************************************************/

typedef struct s_http_target
{
	char		*name;
	t_address	address;
	char		*method;
	char		*code;
	int			frequency;
}				t_http_target;

/******************************************************************************\
 * PING
\******************************************************************************/

typedef struct s_ping_target
{
	char		*name;
	t_address	address;
	int			frequency;
}				t_ping_target;

/******************************************************************************\
 * DNS
\******************************************************************************/

typedef struct s_dns_target
{
	char		*name;
	t_address	address;
	int			frequency;
	t_address	server;
}				t_dns_target;

#endif

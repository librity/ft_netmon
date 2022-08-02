/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 17:02:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <termios.h>

/******************************************************************************\
 * TTY
\******************************************************************************/

typedef struct termios	t_termios;

/******************************************************************************\
 * FILES
\******************************************************************************/

typedef struct s_file
{
	char				*path;
	int					fd;
}						t_file;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_control
{
	int					argc;
	char				**argv;

	t_termios			original_tty_attr;

	bool				help_flag;
	bool				simplify_flag;
	bool				debug_flag;

	t_file				config;
	t_file				log;

	t_dlist				*targets;

	t_list				*lalloc;
}						t_control;

/******************************************************************************\
 * NETWORK
\******************************************************************************/

typedef struct s_address
{
	char				*name;
	char				*ipv4;
	char				*ipv6;
}						t_address;

/******************************************************************************\
 * TARGETS
\******************************************************************************/

typedef enum e_protocol
{
	NO_PROTOCOL = 0,
	HTTP_PROT,
	HTTPS_PROT,
	PING_PROT,
	DNS_PROT
}						t_protocol;

typedef struct s_target
{
	t_protocol			protocol;
	char				*name;
	t_address			address;
	int					frequency;

	char				*method;
	char				*code;

	t_address			dns;
}						t_target;

/******************************************************************************\
 * REQUESTS
\******************************************************************************/

typedef struct s_request
{
	t_target			*target;

	char				*url;

	time_t				start;
	time_t				end;

	clock_t				clock;
	double				latency;

	t_lstr				response;
	char				*code;
	CURLcode			curl_code;

	bool				error;
	char				*error_message;
}						t_request;

/******************************************************************************\
 * THREADS
\******************************************************************************/

typedef enum e_tstatus
{
	THREAD_ERR = -1,
	THREAD_EXIT_OK,
	THREAD_RUNNING
}						t_tstatus;

typedef struct s_thread
{
	pthread_t			id;
	t_tstatus			status;
}						t_thread;

typedef void			*(*t_troutine)(void *);

typedef pthread_mutex_t	t_tmutex;
typedef pthread_cond_t	t_tcond;

/******************************************************************************\
 * THREAD POOL CONTROL
\******************************************************************************/

typedef struct s_tpcontrol
{
	t_dlist				*workers;
	t_dlist				*schedulers;

	t_target			*request_queue[REQUEST_QUEUE_SIZE];
	int					request_count;

	t_tmutex			queue_mutex;
	t_tcond				queue_cond;
}						t_tpcontrol;

#endif

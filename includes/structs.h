/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 23:13:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <netdb.h>
# include <netinet/ip_icmp.h>
# include <termios.h>

/******************************************************************************\
 * TTY
\******************************************************************************/

typedef struct termios		t_termios;

/******************************************************************************\
 * FILES
\******************************************************************************/

typedef struct s_file
{
	char					*path;
	int						fd;
	FILE					*fs;
}							t_file;

/******************************************************************************\
 * TIME
\******************************************************************************/

typedef struct timeval		t_timeval;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_control
{
	int						argc;
	char					**argv;

	t_termios				original_tty_attr;

	bool					help_flag;
	bool					simplify_flag;
	bool					debug_flag;

	t_file					config;
	t_file					log;

	t_dlist					*targets;

	t_list					*lalloc;
}							t_control;

/******************************************************************************\
 * NETWORK
\******************************************************************************/

typedef struct s_address
{
	char					*name;
	char					*ipv4;
	char					*ipv6;
}							t_address;

typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_inet_sockaddr;
typedef struct sockaddr_in6	t_inet6_sockaddr;
typedef struct addrinfo		t_addrinfo;
typedef struct icmphdr		t_icmphdr;

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
}							t_protocol;

typedef struct s_target
{
	t_protocol				protocol;
	char					*name;
	t_address				address;
	int						frequency_sec;

	char					*method;
	char					*code;

	t_address				dns;
}							t_target;

/******************************************************************************\
 * REQUESTS
\******************************************************************************/

typedef struct s_request
{
	t_target				*target;
	time_t					start;
	time_t					end;
	clock_t					clock;
	double					latency_msec;
	bool					error;
	char					*error_message;

	char					*url;
	char					*code;
	t_lstr					response;

	char					*ipv4;
}							t_request;

/******************************************************************************\
 * HTTP
\******************************************************************************/

typedef struct s_http
{
	t_request				*req;
	t_inet_sockaddr			servaddr;
	char					send_buffer[HTTP_BUFFER_SIZE];
	char					recv_buffer[HTTP_BUFFER_SIZE];
	int						socket;
	char					*content;
	char					**header_tokens;
	char					*err;
}							t_http;

/******************************************************************************\
 * PING
\******************************************************************************/

typedef struct s_ping_packet
{
	t_icmphdr				hdr;
	char					msg[PING_PACKET_SIZE - sizeof(t_icmphdr)];
}							t_ping_packet;

typedef struct s_ping
{
	t_request				*req;
	t_inet_sockaddr			sendaddr;
	t_inet_sockaddr			recvaddr;
	t_ping_packet			packet;
	int						raw_socket;
	char					*err;
}							t_ping;

/******************************************************************************\
 * DNS
\******************************************************************************/

typedef struct s_dns_query
{
	uint16_t				length;
	unsigned char			message[DNS_BUFFER_SIZE];
}							t_dns_query;

typedef struct s_dns
{
	t_request				*req;
	t_dns_query				query;
	t_inet_sockaddr			addr;
	int						socket;
	int						bytes_received;
	unsigned char			res_buff[DNS_BUFFER_SIZE];
	char					*err;
}							t_dns;

/******************************************************************************\
 * LOG
\******************************************************************************/

typedef struct s_log
{
	char					*type;
	char					*start;
	char					*end;
	char					*protocol;
	char					*name;
	char					*address;
	char					*has_error;
	char					*error_message;
	int						frequency_sec;
	double					latency_msec;

	char					*url;
	char					*method;
	char					*target_code;
	char					*response_code;
	int						response_length;

	char					*ipv4;

	char					*domain;
	char					*dns_ip;
}							t_log;

/******************************************************************************\
 * THREADS
\******************************************************************************/

typedef enum e_tstatus
{
	THREAD_ERR = -1,
	THREAD_EXIT_OK,
	THREAD_RUNNING
}							t_tstatus;

typedef struct s_thread
{
	pthread_t				id;
	t_tstatus				status;
}							t_thread;

typedef void				*(*t_troutine)(void *);

typedef pthread_mutex_t		t_tmutex;
typedef pthread_cond_t		t_tcond;

/******************************************************************************\
 * THREAD POOL CONTROL
\******************************************************************************/

typedef struct s_tpcontrol
{
	t_dlist					*workers;
	int						workers_count;

	t_dlist					*schedulers;

	t_target				*request_queue[REQUEST_QUEUE_SIZE];
	int						request_count;

	t_tmutex				queue_mutex;
	t_tcond					queue_cond;
}							t_tpcontrol;

#endif

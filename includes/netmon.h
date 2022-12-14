/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netmon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 22:35:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETMON_H
# define NETMON_H

# include <arpa/inet.h>
# include <curl/curl.h>
# include <defines.h>
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <structs.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_control	*c(void);
void		initialize_control(int argc, char **argv);

t_termios	original_tty_attr(void);
void		save_tty_flags(void);

int			argc(void);
char		**argv(void);

bool		help_flag(void);
void		enable_help_flag(void);

bool		simplify_flag(void);
void		enable_simplify_flag(void);

bool		debug(void);
bool		debug_flag(void);
void		enable_debug_flag(void);

char		*config_path(void);
void		set_config_path(char *path);

int			config_fd(void);
void		open_config(void);
void		close_config(void);

char		*log_path(void);
void		set_log_path(char *path);

int			log_fd(void);
void		open_log(void);
void		close_log(void);

FILE		*log_fs(void);
void		open_log_fs(void);
void		close_log_fs(void);

t_dlist		**targets(void);
int			targets_count(void);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * FLAGS
\******************************************************************************/

void		handle_flags(void);
void		parse_flags(void);
void		validate_flags(void);

bool		handled_bool_flag(char *argument);
bool		is_bool_flag(char *argument);

bool		handled_file_flag(char **arguments);
bool		is_file_flag(char *argument);

bool		handled_int_flag(char **arguments);
bool		is_int_flag(char *argument);

bool		next_is_flag(char **arguments);

/******************************************************************************\
 * CONFIG
\******************************************************************************/

void		handle_config(void);

bool		is_valid_protocol(char *field);
char		*get_protocol_by_code(t_protocol code);

/******************************************************************************\
 * CONFIG PARSER
\******************************************************************************/

void		parse_config_file(void);
void		parse_fields(char **fields);

void		parse_http(char **fields);
void		parse_https(char **fields);
void		parse_ping(char **fields);
void		parse_dns(char **fields);

char		*extract_field(char **fields, int index);
char		*get_protocol(char **fields);
char		*get_field(char *protocol, char **fields, int index);

/******************************************************************************\
 * CONFIG VALIDATORS
\******************************************************************************/

void		validate_fields(char **fields);

void		validate_http(char **fields);
void		validate_https(char **fields);
void		validate_ping(char **fields);
void		validate_dns(char **fields);

bool		is_valid_frequency(char *str);

/******************************************************************************\
 * TARGETS
\******************************************************************************/

t_target	*new_target(void);
void		inspect_target(void *t);
t_target	*nget_target(t_dlist *node);

/******************************************************************************\
 * HTTP
\******************************************************************************/

bool		is_http_method(char *field);

bool		is_http_code(char *field);
char		*get_http_code_string(long code_number);

typedef struct s_new_http_target
{
	char	*name;
	char	*address;
	char	*method;
	char	*code;
	int		frequency;
}			t_new_http_target;
void		add_http_target(t_new_http_target p);

void		handle_http_request(t_target *target);

char		*handle_http(t_request *request);
void		http_prepare_content(t_http *h);
void		http_prepare_address(t_http *h);
void		http_prepare_socket(t_http *h);
void		http_send_and_receive(t_http *h);
void		http_validate_response(t_http *h);

/******************************************************************************\
 * HTTPS
\******************************************************************************/

typedef struct s_new_https_target
{
	char	*name;
	char	*address;
	char	*method;
	char	*code;
	int		frequency;
}			t_new_https_target;
void		add_https_target(t_new_https_target p);

void		handle_https_request(t_target *target);
bool		has_expected_code(t_request *request);

/******************************************************************************\
 * CURL
\******************************************************************************/

char		*handle_curl(t_request *request);
void		set_request_code(t_request *request, CURL *curl);

/******************************************************************************\
 * PING
\******************************************************************************/

typedef struct s_new_ping_target
{
	char	*name;
	char	*address;
	int		frequency;
}			t_new_ping_target;
void		add_ping_target(t_new_ping_target p);

void		handle_ping_request(t_target *target);

char		*handle_ping(t_request *request);
void		ping_prepare_address(t_ping *p);
void		ping_prepare_socket(t_ping *p);
void		ping_prepare_packet(t_ping_packet *packet);
void		ping_send_and_receive(t_ping *p);

/******************************************************************************\
 * DNS
\******************************************************************************/

typedef struct s_new_dns_target
{
	char	*name;
	char	*address;
	int		frequency;
	char	*dns_ipv4;
}			t_new_dns_target;
void		add_dns_target(t_new_dns_target p);

void		handle_dns_request(t_target *target);

char		*handle_dns(t_request *request);
void		dns_prepare_query(t_dns *d);
void		dns_prepare_address(t_dns *d);
void		dns_send_and_receive(t_dns *d);
void		dns_extract_ip(t_dns *d);

/******************************************************************************\
 * REQUESTS
\******************************************************************************/

void		handle_request(t_target *target);

void		initialize_request(t_request *new, t_target *target);
void		destroy_request(t_request *request);

void		handle_request_error(t_request *request, char *error_message);
void		handle_request_success(t_request *request);

void		start_time(t_request *request);
void		end_time(t_request *request);
void		start_clock(t_request *request);
void		stop_clock(t_request *request);

typedef struct s_req_error
{
	char	*time;
	char	*name;
	char	*protocol;
	char	*address;
	char	*error_message;
}			t_req_error;
void		put_request_error(t_req_error req_error);

typedef struct s_req_success
{
	char	*time;
	char	*protocol;
	char	*name;
	char	*address;
	double	latency;
}			t_req_success;
void		put_request_success(t_req_success req_success);

/******************************************************************************\
 * LOG
\******************************************************************************/

void		log_request(t_request *request);

void		log_http_request(t_request *request);
void		log_https_request(t_request *request);
void		log_ping_request(t_request *request);
void		log_dns_request(t_request *request);

char		*resolve_log_type(t_request *request);
char		*resolve_log_error(t_request *request);

void		destroy_log(t_log *log);

/******************************************************************************\
 * SIMPLIFY
\******************************************************************************/

void		simplify_log(void);

void		simplify_fields(char **fields);

/******************************************************************************\
 * THREADS
\******************************************************************************/

void		disable_cancellation(void);
void		enable_cancellation(void);

void		switch_deffered(void);
void		switch_async(void);

t_thread	*find_self(void);
t_thread	*find_self_or_tdie(void);

t_thread	*find_thread_in_index(t_dlist **threads, pthread_t id);
t_thread	*find_thread(pthread_t id);

t_thread	*nget_thread(t_dlist *node);
pthread_t	nget_thread_id(t_dlist *node);
t_tstatus	nget_thread_status(t_dlist *node);

void		set_self_status(t_tstatus status);

void		tdie(char *error_message);

/******************************************************************************\
 * MAIN THREAD
\******************************************************************************/

t_thread	*new_thread(void);
void		add_thread(t_dlist **threads);

void		initialize_n_threads(t_dlist **threads, int n);
void		nspawn_thread(t_dlist *node, t_troutine routine, void *thread_arg);
void		spawn_threads(t_dlist **threads, t_troutine routine,
				void *thread_arg);
void		create_threads(t_dlist **threads, t_troutine routine,
				void *thread_arg, int thread_count);

void		cancel_threads(t_dlist **threads);
void		join_threads(t_dlist **threads);

void		initialize_mutex(t_tmutex *mutex);
void		destroy_mutex(t_tmutex *mutex);

void		initialize_cond(t_tcond *cond);
void		destroy_cond(t_tcond *cond);

/******************************************************************************\
 * THREAD POOL CONTROL
\******************************************************************************/

t_tpcontrol	*tpc(void);
void		initialize_thread_pool_control(void);

t_dlist		**workers(void);
int			count_workers(void);

int			workers_count(void);
void		set_workers_count(int new_count);

t_dlist		**schedulers(void);
int			count_schedulers(void);

void		enqueue_request(t_target *target);
t_target	*dequeue_request(void);

int			request_count(void);
void		increase_request_count(void);
void		decrease_request_count(void);

t_tmutex	*queue_mutex(void);
t_tcond		*queue_cond(void);

/******************************************************************************\
 * THREAD POOL
\******************************************************************************/

void		initialize_thread_pool(void);
void		close_thread_pool(void);

void		create_schedulers(void);
void		cancel_schedulers(void);
void		join_schedulers(void);

void		create_workers(void);
void		cancel_workers(void);
void		join_workers(void);

void		*run_scheduler(void *target_vp);
void		*run_worker(void *_args);

void		enqueue_safely(t_target *target);
t_target	*dequeue_safely(void);

/******************************************************************************\
 * THREAD SAFE
\******************************************************************************/

void		ts_fprintf(FILE *filehandle, const char *format, ...);
void		ts_printf(const char *format, ...);

char		*ts_asctime(void);
char		*ts_raw_to_asctime(time_t *rawtime);

char		*ts_logtime(void);
char		*ts_raw_to_logtime(time_t *rawtime);

void		localtime_or_die(time_t *rawtime, t_timeinfo *timeinfo);
void		utctime_or_die(time_t *rawtime, t_timeinfo *timeinfo);

/******************************************************************************\
 * FILES
\******************************************************************************/

int			create_file_or_die(char *path);
FILE		*create_fs_or_die(char *path);

int			open_file_or_die(char *path);

int			close_or_die(int close_me);
FILE		*close_fs_or_die(FILE *close_me);

/******************************************************************************\
 * IP
\******************************************************************************/

bool		is_valid_ipv4(char *address);
bool		is_valid_ipv6(char *address);

char		*lookup_ipv4(char *name);
char		*lookup_ipv6(char *name);

/******************************************************************************\
 * SOCKETS
\******************************************************************************/

bool		can_use_raw_sockets(void);
int			create_raw_socket(void);
int			create_raw_socket_or_die(void);

int			create_datagram_socket(void);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void		initialize(int argc, char **argv);

void		handle_monitoring(void);

void		disable_tty_raw_mode(void);
void		enable_tty_raw_mode(void);

void		handle_key(void);

void		cleanup(void);

void		quit(void);
void		help_and_quit(void);
void		simplify_and_quit(void);
void		close_thread_pool_and_quit(void);

void		die(char *error_message);
void		free_and_die(void *free_me, char *error_message);
void		free_arr_and_die(char **free_me, char *error_message);

void		print_error(char *message);
void		print_warning(char *message);

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void		tdebug(const char *format, ...);
void		tbdebug(bool _debug, const char *format, ...);

void		debug_flags(void);
void		debug_bool_flag(char *flag_name, bool flag);
void		debug_file_flag(char *flag_name, char *file_path);
void		debug_int_flag(char *flag_name, int number);

void		debug_targets(void);
void		debug_key(char key);

#endif

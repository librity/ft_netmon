/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 00:00:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <fcntl.h>
# include <arpa/inet.h>
# include <curl/curl.h>
# include <errno.h>

# include <defines.h>
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

void		close_files(void);

t_dlist		**targets(void);

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

void		simplify_and_quit(void);

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
void		validate_ping(char **fields);
void		validate_dns(char **fields);

bool		is_valid_frequency(char *str);

/******************************************************************************\
 * TARGETS
\******************************************************************************/

t_target	*new_target(void);

/******************************************************************************\
 * HTTP
\******************************************************************************/

bool		is_http_method(char *field);
bool		is_http_code(char *field);

typedef struct s_new_http_target
{
	char	*name;
	char	*address;
	char	*method;
	char	*code;
	int		frequency;
}			t_new_http_target;
void		add_http_target(t_new_http_target p);

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

/******************************************************************************\
 * FILES
\******************************************************************************/

int			create_file_or_die(char *path);
int			open_file_or_die(char *path);
int			close_or_die(int close_me);

/******************************************************************************\
 * IP
\******************************************************************************/

bool		is_valid_ipv4(char *address);
bool		is_valid_ipv6(char *address);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void		initialize(int argc, char **argv);

void		disable_tty_raw_mode(void);
void		enable_tty_raw_mode(void);

void		handle_key(void);

void		cleanup(void);

void		quit(void);
void		help_and_quit(void);

void		die(char *error_message);
void		free_and_die(void *free_me, char *error_message);
void		free_arr_and_die(char **free_me, char *error_message);

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void		debug_flags(void);
void		debug_targets(void);
void		debug_key(char key);

#endif

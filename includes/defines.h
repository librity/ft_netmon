/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 17:59:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * HELP
\******************************************************************************/

# define HELP_MSG "Welcome to lpaulo-m's network monitoring service!\n\
\n\
USAGE:\
	monitoring [OPTIONS]...\
\
OPTIONS:\
	--config-file=<file> \
			Config file path (default ./monitoring.db)\
	--log-file=<file> \
			Log file path (default ./monitoring.log)\
	--simplify\
			???\
	-h, --help\
			Print this help message.\
\
CONFIG FILE FORMAT:\
=========================================================================================\
|PROTOCOL	|ROWS (tab separated)														|\
=========================================================================================\
|HTTP		|name	HTTP	address		http_method		expected_http_code		timeout	|\
|PING		|name	PING	address		timeout											|\
|DNS		|name	DNS		address		timeout			dns_server						|\
=========================================================================================\
\n\
"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CREATE_PERMISSION 0000664

/******************************************************************************\
 * CONFIG
\******************************************************************************/

# define DEFAULT_CONFIG_PATH "./monitoring.db"
# define DEFAULT_LOG_PATH "./monitoring.log"

/******************************************************************************\
 * SHELL
\******************************************************************************/

# define CLEAR_REGEX "\e[1;1H\e[2J"

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define GENERIC_ERR "ERROR\n"
# define FILE_CREATE_ERR "ERROR: Unable to create necessary file.\n"
# define FILE_OPEN_ERR "ERROR: Unable to open necessary file.\n"
# define FD_CLOSE_ERR "ERROR: Unable to close necessary file descriptor.\n"

#endif

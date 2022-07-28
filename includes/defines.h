/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 19:26:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * HELP
\******************************************************************************/

# define HELP_MSG "Welcome to lpaulo-m's network monitoring service!\n\
\033[0;33m \n\
USAGE: \033[0m\n\
	monitoring [OPTIONS]...\n\
\033[0;33m \n\
OPTIONS: \033[0m \n\
\033[1;32m	-h, --help \033[0m\n\
		Print this help message.\n\
\n\
\033[1;32m	--simplify \033[0m\n\
		???\n\
\n\
\033[1;32m	--config-file <file> \033[0m\n\
		Config file path (default ./monitoring.db)\n\
\n\
\033[1;32m	--log-file <file> \033[0m\n\
		Log file path (default ./monitoring.log)\n\
\033[0;33m\n\
CONFIG FILE FORMAT: \033[0m\n\
\n\
	\033[0;34m====================================================================================== \033[0m\n\
	\033[0;34m|\033[0m PROTOCOL \033[0;34m|\033[0m ROWS (tab separated)                                                    \033[0;34m|\033[0m\n\
	\033[0;34m====================================================================================== \033[0m\n\
	\033[0;34m|\033[0m HTTP     \033[0;34m|\033[0m name    HTTP    address    http_method    expected_http_code    timeout \033[0;34m|\033[0m\n\
	\033[0;34m|\033[0m PING     \033[0;34m|\033[0m name    PING    address    timeout                                      \033[0;34m|\033[0m\n\
	\033[0;34m|\033[0m DNS      \033[0;34m|\033[0m name    DNS     address    timeout        dns_server                    \033[0;34m|\033[0m\n\
	\033[0;34m====================================================================================== \033[0m\n\
\033[0;33m\n\
EXAMPLE: \033[0m\n\
\033[1;36m \n\
\"\"\"\n\
# monitoring.db\n\
\n\
# COMMENTS ARE ALLOWED\n\
intra	HTTP	intra.42.fr	GET	200	120\n\
game ping test	PING	game.42sp.org.br	60\n\
workspaces monitoring	PING	workspaces.42sp.org.br	60\n\
\"\"\" \033[0m\n\
\033[0m \n\
"

/******************************************************************************\
 * DEFAULTS
\******************************************************************************/

# define DEFAULT_CONFIG_PATH "./monitoring.db"
# define DEFAULT_LOG_PATH "./monitoring.log"

/******************************************************************************\
 * FLAGS
\******************************************************************************/

# define HELP_FLAG_1 "-h"
# define HELP_FLAG_2 "--help"
# define SIMPLIFY_FLAG "--simplify"
# define CONFIG_FILE_FLAG "--config-file"
# define LOG_FILE_FLAG "--log-file"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CREATE_PERMISSION 0000664

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
# define FILE_FLAG_NULL_PATH_ERR "ERROR: \
File flags must be followed by a file path argument.\n"

#endif

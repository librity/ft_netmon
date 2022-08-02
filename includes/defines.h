/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 12:28:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <help.h>
# include <http.h>
# include <ping.h>
# include <dns.h>
# include <errors.h>
# include <banners.h>

/******************************************************************************\
 * TTY
\******************************************************************************/

# define CONTROL_C 3
# define CONTROL_D 4
# define CONTROL_Q 17
# define CONTROL_S 19

# define CONTROLS_HELP "Press CONTROL+Q to exit the program cleanly. \
Press CONTROL+C to exit the program."

/******************************************************************************\
 * DEFAULTS
\******************************************************************************/

# define DEFAULT_CONFIG_PATH "./monitoring.db"
# define DEFAULT_LOG_PATH "./monitoring.log"

/******************************************************************************\
 * FLAGS
\******************************************************************************/

# define HELP_FLAG "--help"
# define HELP_FLAG_SHORT "-h"
# define HELP_FLAG_NAME "help"

# define SIMPLIFY_FLAG "--simplify"
# define SIMPLIFY_FLAG_SHORT "-s"
# define SIMPLIFY_FLAG_NAME "simplify"

# define DEBUG_FLAG "--debug"
# define DEBUG_FLAG_SHORT "-d"
# define DEBUG_FLAG_NAME "debug"

# define CONFIG_FILE_FLAG "--config-file"
# define CONFIG_FILE_FLAG_NAME "Config file"

# define LOG_FILE_FLAG "--log-file"
# define LOG_FILE_FLAG_NAME "Log file"

/******************************************************************************\
 * CONFIG
\******************************************************************************/

# define COMMENT_INDICATOR '#'
# define FIELD_SEPARATOR '\t'
# define PROTOCOL_INDEX 1
# define FREQUENCY_FIELD_MAX_LENGTH 10

/******************************************************************************\
 * THREAD POOL
\******************************************************************************/

# define WORKERS_COUNT 8

# define REQUEST_QUEUE_SIZE 500

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CREATE_PERMISSION 0000664
# define CLOSED_FD -1

/******************************************************************************\
 * TIME
\******************************************************************************/

typedef struct tm	t_timeinfo;

# define TIME_BUFFER_SIZE 26

#endif

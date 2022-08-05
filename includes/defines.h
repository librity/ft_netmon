/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/05 15:01:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <banners.h>
# include <dns.h>
# include <errors.h>
# include <help.h>
# include <http.h>
# include <ping.h>
# include <warnings.h>

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

# define WORKERS_FLAG "--workers"
# define WORKERS_FLAG_SHORT "-w"
# define WORKERS_FLAG_NAME "Initial worker threads"

/******************************************************************************\
 * CONFIG
\******************************************************************************/

# define COMMENT_INDICATOR '#'
# define FIELD_SEPARATOR '\t'
# define PROTOCOL_INDEX 1
# define FREQUENCY_FIELD_MAX_LENGTH 10

/******************************************************************************\
 * LOG
\******************************************************************************/

# define LOG_INFO "[INFO]"
# define LOG_ERROR "[ERROR]"

# define LOG_TRUE "TRUE"
# define LOG_FALSE "FALSE"

/******************************************************************************\
 * SIMPLIFY
\******************************************************************************/

# define LOG_TYPE_INDEX 0
# define LOG_START_INDEX 1
# define LOG_END_INDEX 2
# define LOG_PROTOCOL_INDEX 3
# define LOG_NAME_INDEX 4
# define LOG_ADDRESS_INDEX 5
# define LOG_HAS_ERROR_INDEX 6
# define LOG_ERROR_MESSAGE_INDEX 7
# define LOG_LATENCY_INDEX 8

/******************************************************************************\
 * IP
\******************************************************************************/

# define IPV4_ADDRESS_STRING_SIZE 16
# define IPV6_ADDRESS_STRING_SIZE 170

/******************************************************************************\
 * THREADS
\******************************************************************************/

# define MAX_WORKER_THREADS 500

/******************************************************************************\
 * THREAD POOL
\******************************************************************************/

# define DEFAULT_WORKERS_COUNT 8
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

# define ASCTIME_STRING_SIZE 26

#endif

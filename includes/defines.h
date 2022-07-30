/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 23:29:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <help.h>
# include <http.h>
# include <ping.h>
# include <dns.h>
# include <errors.h>

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

# define SIMPLIFY_FLAG "--simplify"
# define SIMPLIFY_FLAG_SHORT "-s"

# define CONFIG_FILE_FLAG "--config-file"
# define LOG_FILE_FLAG "--log-file"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CREATE_PERMISSION 0000664
# define CLOSED_FD -1

/******************************************************************************\
 * CONFIG
\******************************************************************************/

# define COMMENT_INDICATOR '#'
# define FIELD_SEPARATOR '\t'
# define PROTOCOL_INDEX 1
# define FREQUENCY_FIELD_MAX_LENGTH 10

/******************************************************************************\
 * SHELL
\******************************************************************************/

# define CLEAR_REGEX "\e[1;1H\e[2J"

#endif

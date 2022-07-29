/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 02:29:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define GENERIC_ERR "no no bad bad bad.\n"

# define FILE_CREATE_ERR "Unable to create necessary file.\n"
# define FILE_OPEN_ERR "Unable to open necessary file.\n"
# define FD_DOUBLE_CLOSE_ERR "Closing a closed file descriptor.\n"
# define FD_CLOSE_ERR "Unable to close necessary file descriptor.\n"

# define FILE_FLAG_NULL_PATH_ERR "File flags must be followed by \
a file path argument.\n"
# define EQUAL_FILE_PATHS_ERR "Config and log file paths must be different.\n"

# define DOUBLE_OPEN_CONFIG_ERR "Config file descriptor already open.\n"
# define CONFIG_READ_ERR "Couldn't read config file.\n"

# define DOUBLE_OPEN_LOG_ERR "Log file descriptor already open.\n"
# define LOG_READ_ERR "Couldn't read log file.\n"

# define CONFIG_PROTOCOL_ERR "Invalid monitoring protocol in config file.\n"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 11:25:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define GENERIC_ERR "no no bad bad bad."

/******************************************************************************\
 * TTY
\******************************************************************************/

# define TTY_EMPTY_ATTR_ERR "Original tty attributes are empty."
# define TTY_GET_ATTR_ERR "Can't get original tty attributes."
# define TTY_SET_ATTR_ERR "Can't set raw mode tty attributes."
# define TTY_RESTORE_ATTR_ERR "Can't restore original tty attributes."

# define READ_KEY_ERR "Can't read next input key from STDIN_FILENO."

/******************************************************************************\
 * FILES
\******************************************************************************/

# define FILE_CREATE_ERR "Can't create necessary file."
# define FILESTREAM_CREATE_ERR "Can't create stream to necessary file."

# define FILE_OPEN_ERR "Can't open necessary file."

# define FD_DOUBLE_CLOSE_ERR "Closing a closed file descriptor."
# define FS_DOUBLE_CLOSE_ERR "Closing a closed file stream."
# define FD_CLOSE_ERR "Can't close necessary file descriptor."
# define FS_CLOSE_ERR "Can't close necessary file stream."

/******************************************************************************\
 * FLAGS
\******************************************************************************/

# define FILE_FLAG_NULL_PATH_ERR "File flags must be followed by \
a file path argument."
# define EQUAL_FILE_PATHS_ERR "Config and log file paths must be different."
# define BAD_FLAGS_ERR "Invalid flag or flags. \
Run program with --help for flags and usage."

/******************************************************************************\
 * CONFILE FILE
\******************************************************************************/

# define DOUBLE_OPEN_CONFIG_ERR "Config file descriptor already open."
# define CONFIG_READ_ERR "Couldn't read config file."

/******************************************************************************\
 * LOG FILE
\******************************************************************************/

# define DOUBLE_OPEN_LOG_ERR "Log file descriptor already open."
# define LOG_READ_ERR "Couldn't read log file."

# define DOUBLE_OPEN_LOG_STREAM_ERR "Log file file already open."

/******************************************************************************\
 * CONFIG
\******************************************************************************/

# define CONFIG_PROTOCOL_ERR "Invalid monitoring protocol in config file."

/******************************************************************************\
 * REQUESTS
\******************************************************************************/

# define BAD_PROTOCOL_ERR "Invalid request protocol."

/******************************************************************************\
 * HTTPS
\******************************************************************************/

# define CURL_INIT_ERR "Can't initialize libcurl request."
# define HTTPS_BAD_CODE "HTTPS response code doesn't match expected code."

/******************************************************************************\
 * PING
\******************************************************************************/

# define PING_DNS_ERR "Can't resolve target IPv4 address."
# define PING_RAW_SOCKET_ERR "Can't create raw socket."
# define PING_TTL_ERR "Can't set socket's time to live."
# define PING_TIMEOUT_ERR "Can't set socket's time to live."
# define PING_PACKET_ERR "Can't send ICMP packet to target."
# define PING_RECEIVE_ERR "Can't receive ICMP packet from target."
# define PING_CODE_ERR "ICMP packet response returned invalid code."

/******************************************************************************\
 * DNSPING
\******************************************************************************/

# define DNS_DATAGRAM_SOCKET_ERR "Can't create datagram socket."
# define DNS_SEND_ERR "Can't send DNS query to target server."
# define DNS_RECEIVE_ERR "Can't receive DNS query response."
# define DNS_SERVER_ERR "DNS server returned an error."
# define DNS_NOT_FOUND_ERR "DNS server couldn't resolve the domain name\
to an IP address."
# define DNS_NO_IPS_ERR "DNS response didn't contain any IP addresses."

/******************************************************************************\
 * IP
\******************************************************************************/

# define IPV4_VALIDATION_ERR "Error validating IPv4 address with inet_pton."
# define IPV6_VALIDATION_ERR "Error validating IPv6 address with inet_pton."

/******************************************************************************\
 * CONFIG VALIDATORS
\******************************************************************************/

# define HTTP_FIELD_COUNT_ERR "HTTP config must have \
six tab-separated fields."
# define HTTP_METHOD_ERR "Invalid HTTP request method.\n\
Valid methods: https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods"
# define HTTP_CODE_ERR "Invalid HTTP response status code.\n\
Valid codes: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status"
# define HTTP_FREQUENCY_ERR "Invalid HTTP monitoring frequency.\n\
Frequency must be a whole number greater than zero, \
representing the interval between requests in seconds."

# define HTTPS_FIELD_COUNT_ERR "HTTPS config must have \
six tab-separated fields."
# define HTTPS_METHOD_ERR "Invalid HTTPS request method.\n\
Valid methods: https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods"
# define HTTPS_CODE_ERR "Invalid HTTPS response status code.\n\
Valid codes: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status"
# define HTTPS_FREQUENCY_ERR "Invalid HTTPS monitoring frequency.\n\
Frequency must be a whole number greater than zero, \
representing the interval between requests in seconds."

# define PING_FIELD_COUNT_ERR "Ping config must have \
four tab-separated fields."
# define PING_FREQUENCY_ERR "Invalid Ping monitoring frequency.\n\
Frequency must be a whole number greater than zero, \
representing the interval between requests in seconds."

# define DNS_FIELD_COUNT_ERR "DNS config must have \
four tab-separated fields."
# define DNS_FREQUENCY_ERR "Invalid DNS monitoring frequency.\n\
Frequency must be a whole number greater than zero, \
representing the interval between requests in seconds."
# define DNS_SERVER_ADDRESS_ERR "Invalid DNS server IPv4 address."

/******************************************************************************\
 * MAIN THREAD
\******************************************************************************/

# define THRD_DUPLICATE_ERR "Encountred a duplicate thread in thread index."

# define THRD_MUTEX_INIT_ERR "Can't initialize required thread mutex."
# define THRD_MUTEX_DESTROY_ERR "Can't destroy required thread mutex."

# define THRD_COND_INIT_ERR "Can't initialize required thread condition."
# define THRD_COND_DESTROY_ERR "Can't destroy required thread condition."

# define THRD_SPAWN_ERR "Can't spawn required thread."
# define THRD_CANCEL_ERR "Can't send required cancel signal to thread."
# define THRD_JOIN_ERR "Can't join required thread."

# define INIT_THREADS_ERR "Can't intialize required threads."

/******************************************************************************\
 * THREADS
\******************************************************************************/

# define THRD_DISABLE_CANCEL_ERR "Can't disable cancellation state of thread."
# define THRD_ENABLE_CANCEL_ERR "Can't enable cancellation state of thread."

# define THRD_SWITCH_DEFFERED_ERR "Can't switch cancelability type of thread \
to deffered."
# define THRD_SWITCH_ASYNC_ERR "Can't switch cancelability type of thread \
to asynchronous."

# define THRD_FIND_ERR "Can't find status."

/******************************************************************************\
 * THREAD POOL CONTROL
\******************************************************************************/

# define REQUEST_COUNT_MIN_ERR "Can't decrease request count further than zero."
# define REQUEST_COUNT_MAX_ERR "Can't increase request count further than \
request queue size."

# define REQUEST_QUEUE_OVERFLOW_ERR "Can't enqueue new request on a full queue."
# define REQUEST_QUEUE_UNDERFLOW_ERR "Can't dequeue request on an empty queue."

/******************************************************************************\
 * THREAD POOL
\******************************************************************************/

# define INIT_SCHEDULERS_ERR "Can't intialize required scheduler threads."
# define SPAWN_SCHEDULERS_ERR "Can't spawn a scheduler thread for each target."

/******************************************************************************\
 * THREAD SAFE
\******************************************************************************/

# define LOCAL_TIME_CONVERT_ERR "Can't convert rawtime to calendar time."
# define UTC_TIME_CONVERT_ERR "Can't convert rawtime to calendar time."

# define ASCTIME_CONVERT_ERR "Can't convert timeinfo to asctime string."
# define LOGTIME_CONVERT_ERR "Can't convert timeinfo to logtime string."

/******************************************************************************\
 * IP
\******************************************************************************/

# define NO_TARGETS_ERR "No targets to monitor."

/******************************************************************************\
 * SOCKETS
\******************************************************************************/

# define RAW_SOCKET_CREATE_ERR "Can't create required raw socket."

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

# define RAW_SOCKET_CAP_ERR "Can't create required raw sockets. \
Check if program is running with administrator privileges (sudo ./monitoring)"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/04 20:50:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# define PING "PING"
# define PING_IDENTIFIER "PING"

# define PING_FIELD_COUNT 4

# define PING_NAME_INDEX 0
# define PING_PROTOCOL_INDEX 1
# define PING_ADDRESS_INDEX 2
# define PING_FREQUENCY_INDEX 3

# define PING_PACKET_SIZE 64
# define AUTOMATIC_PORT_NUMBER 0
# define PING_RECEIVE_TIMEOUT 1
# define PING_TIME_TO_LIVE 64

# define PING_ECHO_REPLY_TYPE 69
# define PING_ECHO_REPLY_CODE 0

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 17:43:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# define HELP_MSG "Welcome to lpaulo-m's network monitoring service!\n\
\033[0;33m \n\
USAGE: \033[0m\n\
	monitoring [OPTIONS]...\n\
\033[0;33m \n\
OPTIONS: \033[0m \n\
\033[1;32m	-h, --help \033[0m\n\
		Print this help message.\n\
\n\
\033[1;32m	-s, --simplify \033[0m\n\
		Print the log file in easily-readable form.\n\
\n\
\033[1;32m	--config-file <file> \033[0m\n\
		Set config file path (default ./monitoring.db)\n\
\n\
\033[1;32m	--log-file <file> \033[0m\n\
		Set log file path (default ./monitoring.log)\n\
\033[0;33m\n\
CONFIG FILE FORMAT: \033[0m\n\
\n\
	\033[0;34m=================================================================================================== \033[0m\n\
	\033[0;34m|\033[0m PROTOCOL \033[0;34m|\033[0m ROWS (tab separated)                                                                 \033[0;34m|\033[0m\n\
	\033[0;34m=================================================================================================== \033[0m\n\
	\033[0;34m|\033[0m HTTP     \033[0;34m|\033[0m name    HTTP    address    http_method    expected_http_code    frequency_in_seconds \033[0;34m|\033[0m\n\
	\033[0;34m|\033[0m PING     \033[0;34m|\033[0m name    PING    address    frequency_in_seconds                                      \033[0;34m|\033[0m\n\
	\033[0;34m|\033[0m DNS      \033[0;34m|\033[0m name    DNS     address    frequency_in_seconds        dns_server                    \033[0;34m|\033[0m\n\
	\033[0;34m=================================================================================================== \033[0m\n\
\033[0;33m\n\
CONFIG FILE EXAMPLE: \033[0m\n\
\033[1;36m \n\
\"\"\"\n\
# monitoring .db\n\
\n\
# THIS IS A COMMENT\n\
intra	HTTP	intra.42.fr	GET	200	120\n\
game ping test	PING	game.42sp.org.br	60\n\
workspaces monitoring	PING	workspaces.42sp.org.br	60\n\
\"\"\" \033[0m\n\
\033[0m \n\
"

#endif

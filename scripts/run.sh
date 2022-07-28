# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/28 17:56:11 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_DIR=""
PUSH_SWAP=""
CHECKER=""

# Value of INT_MAX is +2147483647.
# Value of INT_MIN is -2147483648.

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK="\033[0;30m"
R="\033[0;31m"
G="\033[0;32m"
Y="\033[0;33m"
B="\033[0;34m"
P="\033[0;35m"
C="\033[0;36m"
W="\033[0;37m"
# Bold
BKB="\033[1;30m"
RB="\033[1;31m"
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"
WB="\033[1;37m"
# Reset Color
RC="\033[0m"

divider() {
	echo -e "${P}=======================================================${RC}"
}

separator() {
	divider
	echo
}

################################################################################
# INITIALIZE
################################################################################

make re || exit

################################################################################
# RUN
################################################################################

separator

# ./monitoring
./monitoring -h
./monitoring --help
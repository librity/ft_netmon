/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 13:59:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARNINGS_H
# define WARNINGS_H

# define GENERIC_WARN "you sure about that?"

/******************************************************************************\
 * MAIN THREAD
\******************************************************************************/

# define BUSY_MUTEX_WARN "Trying to destroy locked or referenced mutex: \
https://linux.die.net/man/3/pthread_mutex_destroy"

#endif

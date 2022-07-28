/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 18:51:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <defines.h>
# include <libft.h>
# include <fcntl.h>

typedef struct s_control
{
	int		argc;
	char	**argv;

	bool	help_flag;
	bool	simplify_flag;

	char	*config_path;
	char	*log_path;

	t_list	*lalloc;
}		t_control;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_control	*c(void);
void		initialize_control(int argc, char **argv);

int			argc(void);
char		**argv(void);

bool		help_flag(void);
void		activate_help_flag(void);
bool		simplify_flag(void);
void		activate_simplify_flag(void);

bool		config_path(void);
void		set_config_path(char *path);
bool		log_path(void);
void		set_log_path(char *path);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * FLAGS
\******************************************************************************/

void		handle_flags(void);
void		parse_flags(void);

void		set_simple_flag(char *flag);
bool		is_simple_flag(char *argument);

void		set_file_flag(char **arguments);
bool		is_file_flag(char *arg);

/******************************************************************************\
 * SHELL
\******************************************************************************/

void		clear(void);

/******************************************************************************\
 * FILES
\******************************************************************************/

int			create_file_or_die(char *path);
int			open_file_or_die(char *path);
int			close_or_die(int close_me);

/******************************************************************************\
 *
\******************************************************************************/

void		quit(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(char *error_message);

#endif

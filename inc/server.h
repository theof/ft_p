/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:17:18 by tvallee           #+#    #+#             */
/*   Updated: 2019/02/16 18:11:42 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "common.h"
# include <signal.h>
# include <unistd.h>

typedef	t_ecode	(*t_op_handler)(t_message *msg, t_env *env);

typedef struct	s_master_env
{
	struct s_env	env;
	int				lsock;
	int				port;
	char const		*base_dir;
}				t_master_env;

/*
** worker.c
*/

void			connection_worker(int cs);

/*
** parse_cl.c
*/

t_bool			parse_cl(t_master_env *menv, int ac, char const *av[]);

/*
** master_init.c
*/

int				master_init(t_master_env *menv, int ac, char const *av[]);

/*
** signal.c
*/

t_bool			set_signal_handler(void);
void			reap_children(t_env const *env);

/*
** ../common
*/

t_ecode			pwd_op_handler(t_message *msg, t_env *env);
t_ecode			ping_op_handler(t_message *msg, t_env *env);
t_ecode			cd_op_handler(t_message *msg, t_env *env);
t_ecode			ls_op_handler(t_message *msg, t_env *env);
t_ecode			get_op_handler(t_message *msg, t_env *env);
t_ecode			put_op_handler(t_message *msg, t_env *env);

#endif

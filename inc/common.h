/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:17:48 by tvallee           #+#    #+#             */
/*   Updated: 2019/02/17 18:00:31 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define _DEFAULT_SOURCE
# include <string.h>
# include <assert.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/mman.h>

# include <netdb.h>
# include <stdio.h>
# include <sys/socket.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <arpa/inet.h>
# include <stdarg.h>
# include <dirent.h>
# include <limits.h>
# include "libft.h"
# include "error.h"
# include "message.h"

# define LOG_PADDING 8

typedef struct	s_env
{
	t_bool	should_quit;
	int		csock;
	pid_t	pid;
	int		(*log)(struct s_env const *env, char const *format, ...) __attribute__((format(printf,2,3)));
	char	*root_path;
	char	*cwd_path;
	int		ret;
}				t_env;

typedef struct	s_map
{
	int			fd;
	void		*data;
	off_t		size;
}				t_map;

int				ft_atoi_sane(char const *s, t_bool *sane);

/*
** Those functions block until the socket is closed on the other end or nbytes
** are read/written
*/

ssize_t			sock_raw_read(int fildes, void *buf, ssize_t nbyte);
ssize_t			sock_raw_write(int fildes, void const *buf, ssize_t nbyte);

/*
** sets errno on error
*/
t_ecode			file_map_rd(char const *path, t_map *dst);
t_ecode			file_map_wr(char const *path, off_t size, t_map *dst);
void			file_unmap(t_map *map);

t_bool			is_basename(char const *path);
char const		*ft_basename(char const *path);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:09:03 by emassou           #+#    #+#             */
/*   Updated: 2018/01/05 19:09:05 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define BUFF_SIZE  4

typedef struct	s_struct
{
	char		*tmp;
	char		*tmp2;
	char		b[BUFF_SIZE + 1];
}				t_struct;

int				get_next_line(const int fd, char **line);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:38:21 by emassou           #+#    #+#             */
/*   Updated: 2017/12/06 10:38:22 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int 	ft_saveline(char **buf, char **line)
{
	int size;
	while(**buf != '\0')
	{
		if(ft_strchr(*buf, '\n'))
		{
			size = ft_strchr(*buf, '\n') - *buf;
			*line = ft_strsub(*buf, 0, size);
			*buf = ft_strchr(*buf, '\n') + 1;
			return(1);
		}
		*line = ft_strdup(*buf);
		return(1);
	}
	return(0);
}

int 	ft_read(int ret, int fd, char **buf, char **line)
{
	char	*tmp;
	int 	size;

		tmp = ft_strnew(BUFF_SIZE);
		while ((ret = read(fd, tmp, BUFF_SIZE)))
		{
			tmp[ret] = '\0';
			*buf = ft_strjoin(*buf,tmp);
		}
		free(tmp);
		if(ft_strchr(*buf, '\n'))
		{
			size = ft_strchr(*buf, '\n') - *buf;
			*line = ft_strsub(*buf,0, size);
			*buf = ft_strchr(*buf, '\n') + 1;
		}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;
	int ret;
	
	if(!fd || !*line)
		return (-1);
	if(buf)
		if(ft_saveline(&buf, &*line) == 0) 
			return (1);
	if(!buf)
	{
		buf = ft_strnew(BUFF_SIZE);
		if(ft_read(ret, fd, &buf, &*line) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

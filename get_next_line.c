/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:08:49 by emassou           #+#    #+#             */
/*   Updated: 2018/01/05 19:08:51 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	static char		*stock[BUFF_SIZE + 1];
	t_struct		p;
	int				ret;

	if (fd < 0)
		return (-1);
	if (!stock[fd])
		stock[fd] = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(stock[fd], '\n')) && (ret = read(fd, p.b, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		p.b[ret] = '\0';
		p.tmp = ft_strjoin(stock[fd], p.b);
		ft_strdel(&stock[fd]);
		stock[fd] = p.tmp;
	}
	if (ft_strlen(stock[fd]) == 0)
		return (0);
	*line = ft_strsub(stock[fd], 0, nlen(stock[fd]));
	p.tmp2 = ft_strsub(stock[fd], nlen(stock[fd]) + 1,
	ft_strlen(&stock[fd][nlen(stock[fd])]));
	ft_strdel(&stock[fd]);
	stock[fd] = p.tmp2;
	return (1);
}

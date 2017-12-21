#include "get_next_line.h"

int     nlen(char *str)
{
    int i;
    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    return (i);
}

int     get_next_line(const int fd, char **line)
{
    static t_struct p;
    int             ret;

    if (!p.stock[fd])
        p.stock[fd] = ft_strnew(BUFF_SIZE);
    while (!(ft_strchr(p.stock[fd], '\n')) && (ret = read(fd, p.buf, BUFF_SIZE)))
    {
        if (ret == -1)
            return (-1);
        p.buf[ret] = '\0';
        p.tmp = ft_strjoin(p.stock[fd], p.buf);
        ft_strdel(&p.stock[fd]);
        p.stock[fd] = p.tmp;
    }
    if (ft_strlen(p.stock[fd]) == 0)
        return (0);   
    *line = ft_strsub(p.stock[fd], 0, nlen(p.stock[fd]));
    p.tmp2 = ft_strsub(p.stock[fd], nlen(p.stock[fd]) + 1, ft_strlen(&p.stock[fd][nlen(p.stock[fd])]));
    ft_strdel(&p.stock[fd]);
    p.stock[fd] = p.tmp2;
    return (1);
}

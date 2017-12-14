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
    static char     *str;
    char            *tmp;
    char            buffer[BUFF_SIZE + 1];
    int             ret;
    if (!str)
        str = ft_strnew(BUFF_SIZE);
    while (!(ft_strchr(str, '\n')) && (ret = read(fd, buffer, BUFF_SIZE)) != 0)
    {
        if (ret == -1)
            return (-1);
        buffer[ret] = '\0';
        tmp = ft_strjoin(str, buffer);
        ft_strdel(&str);
        str = tmp;
    }
    if (ft_strlen(str) == 0)
        return (0);
    *line = ft_strsub(str, 0, nlen(str));
    tmp = ft_strsub(str, nlen(str) + 1, ft_strlen(&str[nlen(str)]));
    ft_strdel(&str);
    str = tmp;
    return (1);
}
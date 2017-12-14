
#include "get_next_line.h"
/*
int 	ft_read(int fd, char **buf, char **line)
{
	char	tmp[BUFF_SIZE + 1];
	int		ret;
	int 	size;

		while ((ret = read(fd, tmp, BUFF_SIZE + 1)))
		{
			tmp[ret] = '\0';
			*buf = ft_strjoin(*buf,tmp);
		}
		if(ft_strchr(*buf, '\n'))
		{
			size = ft_strchr(*buf, '\n') - *buf;
			*line = ft_strsub(*buf,0, size);
			*buf = ft_strchr(*buf, '\n') + 1;
		}
	return (ret);
}
*/

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
	return (ret);
}

int 	ft_saveline(char **buf, char **line)
{
	int size;

	if(ft_strchr(*buf, '\n'))
	{
		size = ft_strchr(*buf, '\n') - *buf;
		*line = ft_strsub(*buf, 0, size);
		*buf = ft_strchr(*buf, '\n') + 1;
		return(1);
	}
	*line = ft_strdup(*buf);
	return(0);
}

int main()
{
	int fd;
	char *buf;
	char *line;
	int ret;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
    {
        ft_putstr("open() error");
        return (1);
    }

    if(ft_read(ret, fd, &buf, &line) == -1)
    	return (-1);
    if(ft_strchr(buf, '\n'))
    	ft_putendl(buf);
}

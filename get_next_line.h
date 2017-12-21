#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
	
#define BUFF_SIZE  4096

typedef struct	s_struct
{
	char		*stock[BUFF_SIZE + 1];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
    char        *tmp2;
}               t_struct;
int get_next_line(const int fd, char **line);
	
#endif
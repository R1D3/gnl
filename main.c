/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emassou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:51:47 by emassou           #+#    #+#             */
/*   Updated: 2017/12/06 15:51:49 by emassou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     main()
{
    int     fd;
    char    *line;
	int		i;
    int     j;

    j =0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open() error");
        return (1);
    }
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
        j++;
		printf("LINE %d\n", i);
		ft_putendl(line);
        free (line);
	}
    return (1);
}

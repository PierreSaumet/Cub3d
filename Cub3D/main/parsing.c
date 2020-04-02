/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:34:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:51:43 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/libft.h"
#include <stdio.h>

int		ft_get_info(char *line)
{
	int	i;
	char	tab[9][2];

	tab[0][0] = 'R';
	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
		{
			printf("ok\n tab=%s\n", *tab);
		}
		i++;
	}
	printf("end of get info\n)");
}

int		ft_check(char *argv)
{
	int		i;

	i = 0;
	while(argv[i])
	{
		if (argv[i] == '.')
		{
			if (argv[i + 1] == 'c' && argv[i + 2] == 'u'
					&& argv[i + 3] == 'b' && argv[i + 4] == '\0')
				return (0);
		}
		i++;
	}
	ft_putstr("ERROR, only one argument with the extension '.cub'\n");
	return (1);
}

void	ft_parsing(char *argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	ret = 0;
	line = NULL;
	if (fd == -1)
		printf("Error Fie Descriptor %d\n", fd);
	else
	{
		while ((ret = get_next_line(fd, &line) > 0))
		{
			printf("line = %s\n", line);
			ft_get_info(line);
			free(line);
		}
	}

//	printf("FD = %d, GNL = %d - %s\n", fd, get_next_line(fd, &line), line);
}

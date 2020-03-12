/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:34:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:31:47 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/libft.h"
#include <stdio.h>

int		ft_check(char *argv)
{
	char	*ext;
	char	*tmp;
	int		i;
	int		j;

	ext = "cub";
	i = 0;
	j = 0;
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
	int	fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == 3)
		printf("ok\n");
	else
		printf("Error Fie Descriptor %d\n", fd);
	printf("FD = %d, GNL = %d/%s\n", fd, get_next_line(fd, &line), line);
}

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

#include "../headers/cub3D.h"
#include "../headers/get_next_line.h"
#include "../headers/libft.h"

void		ft_onechar(char *line)
{

}

void		ft_twochar(char *line)
{

}

int			ft_get_res(char *line)
{
	printf("get res line = %s\n", line);
	while (*line != 'R')
	{
		if (*line == ' ')
			line++;
		else
		{
			printf("ERROR DANS R %c\n", *line);
			line++;
		}
			
	}
	line++;
	printf("du coup line =%c\n", *line);
}

int			ft_firstchar(char c)
{
	if (c == 'R' || c == 'S' || c == 'F')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'W')
		return (2);
	else
		return (0);
}

int			ft_get_info(char *line)
{
	int		i;
	t_pars	pars;

	i = 0;
	ft_init_t_pars(&pars);
	while (*line && ft_isspace((int)*line) == 1)
		line++;
	if (ft_isupper((int)*line) == 1 && ft_firstchar(*line) > 0)
	{
		printf("Ok la suite...\n");
		if (ft_firstchar(*line) == 1)
			ft_onechar(line);
		else
			ft_twochar(line);
		
	}
	else
	{
		printf("Erreur, pas pris em compte\n");
		exit(EXIT_FAILURE);
	}
	printf("line=%c\n", *line);
}

void		ft_parsing(char *argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	ret = 0;
	line = NULL;
	if (fd == -1)
		printf("Error File Descriptor %d\n", fd);
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

int			ft_check(char *argv)
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
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
/*
char		*ft_get_r(char *line, t_pars pars)
{
	char	number[56];
	int		count;

	count = 0;
	while (ft_isdigit((int)*line) == 1)
	{
		number[count] = *line;
		count++;
		line++;
	}
	number[count] = '\0';
	if (*pars.pt_rx == 0)
		*pars.pt_rx = ft_atoi((const char *)number);
	else
		*pars.pt_ry = ft_atoi((const char *)number);
	count = 0;
	line++;
	return (line);
}

int			ft_onechar(char *line, t_pars pars)
{
	*pars.pt_rx = 0;
	*pars.pt_ry = 0;
	if (*line == 'R')
	{
		line++;
		while (*line)
		{
			while (ft_isspace((int)*line) == 1)
				line++;
			if (ft_isalpha((int)*line) == 1)
			{
				printf("ERREUR Dans le fichier cub\n");
				exit(0);
			}
			else if (ft_isdigit((int)*line) == 1 && (*pars.pt_rx == 0
					|| *pars.pt_ry == 0))
				line = ft_get_r(line, pars);
		}
		return (1);
	}
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
		{
			printf("Nous avons un R ou S ou F\n");
			ft_onechar(line, pars);
			printf("RESULTAT final : pt_rx = %d et pt_ry= %d\n", *pars.pt_rx, *pars.pt_ry);
		}
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

*/
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

int		ft_onechar(char *line, t_pars pars)
{
	char	number[56];
	int		count;

	count = 0;
	printf("One char line = %s\n", line);
	printf("line = %s et la lettre = %c\n", line, *line);
	/*if (*line == 'R')
	{
		line++;
		while (ft_isspace((int)*line) == 1)
			line++;
		printf("ICI Line = %c\n", *line);
		if (ft_isdigit((int)*line) == 1)
		{
			printf("OK\n");
			number[count] = *line;
			printf("NUMBER = %s\n", number);
		}
		else if (ft_isalpha((int)*line) == 1)
		{
			printf("ERREUR Dans le fichier cub\n");
			exit(0);
		}
		// printf("Line = %c\n", *line);
	}*/
	int a;
	int b;
	a = 0;
	b = 0;
	if (*line == 'R')
	{
		line++;
		*pars.pt_rx = 0;
		*pars.pt_ry = 0;
		while (*line)
		{
			while (ft_isspace((int)*line) == 1)
			{
				printf("lA\n");
				line++;
			}
			if (ft_isalpha((int)*line) == 1)
			{
				printf("ERREUR Dans le fichier cub\n");
				exit(0);
			}
			else if (ft_isdigit((int)*line) == 1)
			{
				printf("OK et *line = -%c-\n", *line);
				while (ft_isdigit((int)*line) == 1)
				{
					number[count] = *line;
					count++;
					line++;
				}
				if (a == 0)
				{
					number[count] = '\0';
					printf("RX NUMBER = %s\n", number);
					a = ft_atoi((const char *)number);
					printf("a = %d\n", a);
					*pars.pt_rx = ft_atoi((const char *)number);
					printf("pt_rx = %d\n", *pars.pt_rx);
				}
				else
				{
					number[count] = '\0';
					printf("RY NUMBER = %s, pt_rx=%d\n", number, *pars.pt_rx);
					b = ft_atoi((const char *)number);
					printf("b = %d\n", b);
					*pars.pt_ry = b;
					printf("pt_ry = %d rx=%d\n", *pars.pt_ry, *pars.pt_rx);
				}
				printf("a %d et b %d\n", a, b);
				count = 0;
				number[count] = '\0';
				line++;
			}
			if (a != 0 && b != 0)
			{

				printf("rx = %d et a = %d\n ry = %d et b = %d\n", *pars.pt_rx, a, *pars.pt_ry, b);
				return (1);
			}
				
		}
	}
	printf("a %d et b %d\n", a, b);
	//pars.pt_rx = &a;
	//pars.pt_ry = &b;
	printf("RESULTAT: pt_rx = %d et pt_ry= %d\n", *pars.pt_rx, *pars.pt_ry);

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
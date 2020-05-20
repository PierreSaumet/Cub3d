/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_test.c                                          :+:      :+:    :+:   */
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

char	*ft_get_rdata(char *line, t_pars pars)
{
	printf("la\n");
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

char	*ft_get_r(char *line, t_pars pars)
{
	line++;
	while (*line)
	{
		if (ft_isspace((int)*line) == 1)
			line++;
		else if (ft_isalpha((int)*line) == 1)
		{
			printf("ERREUR dans le fichier cub\n");
			exit(0);
		}
		else if (ft_isdigit((int)*line) == 1 && (*pars.pt_rx == 0
					|| *pars.pt_ry == 0))
			line = ft_get_rdata(line, pars);
		else
		{
			printf("LOL erreur\n");
			line++;
		}
	}
	return (line);
}

char	*ft_get_fdata(char *line, t_pars pars)
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
	if (*pars.pt_fr == 0)
	{
		*pars.pt_fr = ft_atoi((const char *)number);
		line++;
		if (*line != ',')
			exit(0);
	}
	else if (*pars.pt_fg == 0)
		*pars.pt_fg = ft_atoi((const char *)number);
	else if (*pars.pt_fb == 0)
		*pars.pt_fb = ft_atoi((const char *)number);
	count = 0;
	line++;

	return (line);
}


char	*ft_get_f(char *line, t_pars pars)
{
	line++;
	while (*line)
	{
		if (ft_isspace((int)*line) == 1)
			line++;
		else if (ft_isalpha((int)*line) == 1 || *line == '.')
		{
			printf("ERREUR dans le fichier cub\n");
			exit(0);
		}
		else if (*line == ',')
		{
			printf("il y a une virgule\n");
			line++;
		}
		else if (ft_isdigit((int)*line) == 1)
			line = ft_get_fdata(line, pars);
		else
		{
			printf("LOL erreur line = -%s-, et *line = -%c-\n", line, *line);
			exit(0);
			printf("RESULTAT final : pt_fr = %d et pt_fg= %d et pt_fb= %d\n", *pars.pt_fr, *pars.pt_fg, *pars.pt_fb);
			line++;
		}
	}
	return (line);
}

int		ft_get_data(char *line, t_pars pars)
{
	while (*line)
	{
		if (ft_isspace((int)*line) == 1)
			line++;
		else if (*line == 'R')
			line = ft_get_r(line, pars);
		else if (*line == 'S')
		{
			printf("S\n");
			line++;
		}
		else if (*line == 'F')
			line = ft_get_f(line, pars);
		else if (*line == 'C')
		{
			printf("C\n");
			line++;
		}
		else
		{
			printf("\n1) ERREUR dans le fichier cub  car *line = -%c-\n", *line);
			exit(0);
		}
	}
	return (0);
}

/* Open the file descriptor, and use a function to check the buffer */
void		ft_parsing(char *argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	ret = 0;
	line = NULL;


	int		i;
	t_pars	pars;

	i = 0;
	ft_init_t_pars(&pars);

	if (fd == -1)
		printf("Error File Descriptor %d\n", fd);
	else
	{
		while ((ret = get_next_line(fd, &line) > 0))
		{
			ft_get_data(line, pars);
			free(line);
		}
	}
	printf("\n\n\nRESULTAT final : \n\npt_rx = %d et pt_ry = %d\npt_fr = %d et pt_fg= %d et pt_fb= %d\n", *pars.pt_rx, *pars.pt_ry, *pars.pt_fr, *pars.pt_fg, *pars.pt_fb);

}


/*This function return 1 or 0 if the extension is good */
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
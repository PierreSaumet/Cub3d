/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
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
		printf("\nDEBUT : \n\npt_rx = %d et pt_ry = %d\npt_fr = %d et pt_fg= %d et pt_fb= %d\n\n", *pars.pt_rx, *pars.pt_ry, *pars.pt_fr, *pars.pt_fg, *pars.pt_fb);
		while ((ret = get_next_line(fd, &line) > 0))
		{
			ft_get_data(line, pars);
			free(line);
		}
		printf("\n\n\nRESULTAT final : \n\npt_rx = %d et pt_ry = %d\npt_fr = %d et pt_fg= %d et pt_fb= %d\n", *pars.pt_rx, *pars.pt_ry, *pars.pt_fr, *pars.pt_fg, *pars.pt_fb);
	}
}
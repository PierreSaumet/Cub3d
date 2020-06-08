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
		printf("line = %c et *line = %s dans get data\n", *line, line);
		if (ft_isspace((int)*line) == 1)
			line++;
		else if (*line == 'N')
		{
			line = ft_get_no(line, pars);
			
		}
		else if (*line == 'R')
			line = ft_get_r(line, pars);
		else if (*line == 'F')
			line = ft_get_f(line, pars);
		else if (*line == 'C')
			line = ft_get_c(line, pars);
		else
		{
			printf("\n1) ERREUR dans le fichier cub  car *line = -%c-\n", *line);
			exit(0);
		}
		/*else if (*line == 'R')
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
			line = ft_get_c(line, pars);
		}*/
		
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
	ret = 1;
	line = NULL;


	int		i;
	t_pars	pars;

	i = 0;
	ft_init_t_pars(&pars);

	if (fd == -1)
		printf("Error File Descriptor %d\n", fd);
	else
	{
		//printf("\nDEBUT : \n\npt_rx = %d et pt_ry = %d\npt_fr = %d et pt_fg= %d et pt_fb= %d\n\n", *pars.pt_rx, *pars.pt_ry, *pars.pt_fr, *pars.pt_fg, *pars.pt_fb);
		printf("no =-%s- et pt_no = -%s-\n", pars.no, pars.pt_no);
		while (ret > 0)
		{
			//(ret = get_next_line(fd, &line) > 0)
			ret = get_next_line(fd, &line);
			printf("rest = %d\n", ret);
			ft_get_data(line, pars);
			free(line);
		}
		printf("ret = %d line = %s\n", ret, line);
		printf("\n\n\nRESULTAT final : \n\n	pt_rx = %d et pt_ry = %d\n pt_fr = %d et pt_fg = %d et pt_fb= %d\n pt_cr = %d et pt_cg = %d et pt_cb = %d\n", *pars.pt_rx, *pars.pt_ry, *pars.pt_fr, *pars.pt_fg, *pars.pt_fb, *pars.pt_cr, *pars.pt_cg, *pars.pt_cb);
		printf("rx = %d\n", pars.rx);
		printf("FINAL pars.pt_no = %s\n", pars.pt_no);
		printf("pars.no = %s\n", pars.no);
		free(line);
		line = NULL;
		close(fd);
	}
}
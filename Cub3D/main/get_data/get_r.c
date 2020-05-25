/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:34:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:51:43 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"
#include "../../headers/get_next_line.h"
#include "../../headers/libft.h"

/*
**  ft_get_r checks if the line have no error:
**  if not, use ft_get_rdata to convert strings into int and get the datas.
*/

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
			ft_putstr("ERREUR dans le fichier cub\n");
			exit(0);
		}
		else if (ft_isdigit((int)*line) == 1 && (*pars.pt_rx == 0
					|| *pars.pt_ry == 0))
			line = ft_get_rdata(line, pars);
		else
		{
            ft_putstr("ERREUR dans le fichier cub. \t Donnees non conformes dans F\n");
			exit(0);
		}
	}
	return (line);
}
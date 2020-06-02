/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.c                                            :+:      :+:    :+:   */
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
**  ft_get_f checks if the line have no error:
**  if not, use ft_get_fdata to convert strings into int and get the datas.
*/

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
		//line++;
		printf("line = %s et *line = %c\n", line, *line);
		printf("pt_fr = %d\n\n", *pars.pt_fr);
		if (*line != ',')
        {
            ft_putstr("ERREUR 2 dans le fichier cub. \t Donnees non conformes dans F\n");
            printf("line = %s et *line = %c\n", line, *line);
            exit(0);
        }	
	}
	else if (*pars.pt_fg == 0)
	{
		*pars.pt_fg = ft_atoi((const char *)number);
		//line++;
		printf("line = %s et *line = %c\n", line, *line);
		printf("pt_fg = %d\n\n", *pars.pt_fg);
		if (*line != ',')
        {
            ft_putstr("ERREUR 2 dans le fichier cub. \t Donnees non conformes dans F\n");
            printf("line = %s et *line = %c\n", line, *line);
            exit(0);
        }
	}
	else if (*pars.pt_fb == 0)
	{
		*pars.pt_fb = ft_atoi((const char *)number);
		printf("line = %s et *line = %c\n", line, *line);
		printf("pt_fb = %d\n\n", *pars.pt_fb);
	}
	count = 0;
	//line++;
	return (line);
}

char	*ft_get_f(char *line, t_pars pars)
{
	line++;
	printf("dans F\n");
	while (*line)
	{
		printf("DEBUT DE BOUCLE line = %s et *line = %c\n\n", line, *line);
		if (ft_isspace((int)*line) == 1)
			line++;
		else if (ft_isalpha((int)*line) == 1 || *line == '.')
		{
			ft_putstr("ERREUR F dans le fichier cub alpha ou .\n");
			exit(0);
		}
		else if (*line == ',')
		{
			printf("il y a une virgule *line = %c\n", *line);
			line++;
		}
		else if (ft_isdigit((int)*line) == 1)
			line = ft_get_fdata(line, pars);
		else
		{
            ft_putstr("ERREUR 1 dans le fichier cub. \t Donnees non conformes dans F\n");
			exit(0);
		}
	}
	return (line);
}


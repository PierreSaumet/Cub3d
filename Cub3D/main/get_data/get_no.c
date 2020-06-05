/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no.c                                           :+:      :+:    :+:   */
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

char    *ft_get_no_data(char *line, t_pars pars)
{
    printf("dans no data\n");
    line++;
    char test[128];
    int count;
    count = 0;
    printf("pars.pt no = %s\n", pars.pt_no);
    if (*line == '/')
    {
        printf("line = %c et line = -%s- et strlen = -%d-\n", *line, line, ft_strlen(line));
        line++;
        //if (!(pars.pt_no = malloc(ft_strlen(line) + 1)))
        //    return (NULL);
        while (ft_isalnum((int)*line) == 1)
        {
            pars.no[count] = *line;
            count++;
            line++;
        }
        pars.no[count] = '\0';
        /*if (!(pars.pt_no = malloc(ft_strlen(test) + 1)))
            return (NULL); 
        count = 0;
        while (test[count])
        {
            pars.pt_no[count] = test[count];
            count++;
        }
        pars.pt_no[count] = '\0';*/
        //pars.pt_no = ft_strdup(test);
        printf("test = %s\n", test);
        printf("pars.no = %s \n", pars.no);
    }
    else
    {
        printf("ERROR 12\n");
        exit(0);
    }
    
    return (line);
}

char    *ft_get_no(char *line, t_pars pars)
{
    printf("Dans NO\n");
    line++;
    if (*line == 'O')
    {
        line++;
        while (*line)
        {
            printf("*line = %c\n", *line);
            if (ft_isspace((int)*line) == 1)
                line++;
            else if (ft_isdigit((int)*line) == 1 || ft_isalpha((int)*line) == 1)
            {
                ft_putstr("ERREUR NO dans le fichier cub alpha ou .\n");
			    exit(0);
            }
            else if (*line == '.')
                line = ft_get_no_data(line, pars);
        }
    }
    else
    {
        printf("ERROR dans NO pas de O\n");
        exit(0);
    }
    printf("fin de no, no = %s\n", pars.no);
    return (line);
}
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
#include <string.h>

char    *ft_get_no_data(char *line, t_pars pars)
{
    printf("dans no data\n");
    line++;
    char test[128];
    char *test2;
    int count;
    count = 0;
    printf("pars.pt no = %s\n", pars.pt_no);
    printf("*pars.pt_no = %c\n", *pars.pt_no);
    //printf("&pars,pt_no = %s\n", &pars.pt_no);
    if (*line == '/')
    {
        printf("line = %c et line = -%s- et strlen = -%d-\n", *line, line, ft_strlen(line));
        line++;
        if (!(test2 = malloc(ft_strlen(line) + 1)))
            return NULL;
        
        
        // OK
        
        while (ft_isalnum((int)*line) == 1)
        {
            test2[count] = *line;
            count++;
            line++;
        }
        test2[count] = '\0';
        printf("ok test2 = -%s- et count = -%d-\n", test2, count);
        ft_strcpy(pars.pt_no, test2);
        printf("test = %s\n", test2);
        printf("pars.no = %s \n", pars.pt_no);
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
            printf("lecture ... *line = %c\n", *line);
            if (ft_isspace((int)*line) == 1)
                line++;
            else if (ft_isdigit((int)*line) == 1 || ft_isalpha((int)*line) == 1)
            {
                ft_putstr("ERREUR NO dans le fichier cub alpha ou .\n");
			    exit(0);
            }
            else if (*line == '.')
            {
                line = ft_get_no_data(line, pars);
                printf("dedans ...\n");
            }
        }
    }
    else
    {
        printf("ERROR dans NO pas de O\n");
        exit(0);
    }
    printf("fin de no, pt_no = %s\n", pars.pt_no);
    return (line);
}
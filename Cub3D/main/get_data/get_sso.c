/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sso.c                                          :+:      :+:    :+:   */
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

char    *ft_get_so_data(char *line, t_pars pars, int a)
{
    printf("dans so data\n");
    line++;
    char test[128];
    int count;
    count = 0;
    test[0] = '\0';
    if (*line == '/' && a == 1)
    {
        printf("line = %c et line = -%s- et strlen = -%d-\n", *line, line, ft_strlen(line));
        line++;
        
        // OK
        
        while (ft_isalnum((int)*line) == 1 || *line == '/' || *line == '-' || *line == '_')
        {
            test[count] = *line;
            count++;
            line++;
        }
        test[count] = '\0';
        printf("ok test = -%s- et count = -%d-\n", test, count);
        ft_strcpy(pars.pt_so, test);
        printf("test = %s\n", test);
        printf("pars.so = %s \n", pars.pt_so);
    }
    else if (a == 2)
    {
        printf("POUR S\n");
        line++;
        
        // OK
        
        while (ft_isalnum((int)*line) == 1 || *line == '/' || *line == '-' || *line == '_')
        {
            test[count] = *line;
            count++;
            line++;
        }
        test[count] = '\0';
        printf("ok test = -%s- et count = -%d-\n", test, count);
        ft_strcpy(pars.pt_s, test);
        printf("test = %s\n", test);
        printf("pars.s = %s \n", pars.pt_s);
    }
    else
    {
        printf("ERROR so data\n");
        exit(0);
    }
    
    return (line);
}

char    *ft_get_sso(char *line, t_pars pars)
{
    printf("Dans sso \n");
    line++;
    if (*line == 'O')
    {
        line++;
        while (*line)
        {
            if (ft_isspace((int)*line) == 1)
                line++;
            else if (ft_isdigit((int)*line) == 1 || ft_isalpha((int)*line) == 1)
            {
                ft_putstr("ERREUR SO dans le fichier cub alpha ou .\n");
			    exit(0);
            }
            else if (*line == '.' && *pars.pt_so == '\0')
                line = ft_get_so_data(line, pars, 1);
            else
            {
                printf("ERROR dans SO\n");
                exit(0);
            }
        }
    }
    else if (*line == ' ')
    {
        line++;
        while (*line)
        {
            if (ft_isspace((int)*line) == 1)
                line++;
            else if (ft_isdigit((int)*line) == 1 || ft_isalpha((int)*line) == 1)
            {
                ft_putstr("ERREUR SO dans le fichier cub alpha ou .\n");
			    exit(0);
            }
            else if (*line == '.' && *pars.pt_s == '\0')
                line = ft_get_so_data(line, pars, 2);
            else
            {
                printf("ERROR dans S line = %s et *line = %c\n", line, *line);
                exit(0);
            }
        }
    }
    else
    {
        printf("ERROR dans SSo pas de \n");
        exit(0);
    }
    return (line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_we.c                                           :+:      :+:    :+:   */
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

char    *ft_get_we_data(char *line, t_pars pars)
{
    printf("dans we data\n");
    line++;
    char test[128];
    char *test2;
    int count;
    count = 0;
    test[0] = '\0';
    if (*line == '/')
    {
        printf("line = %c et line = -%s- et strlen = -%d-\n", *line, line, ft_strlen(line));
        line++;
        if (!(test2 = malloc(ft_strlen(line) + 1)))
            return NULL;
        
        
        // OK
        
        while (ft_isalnum((int)*line) == 1 || *line == '/' || *line == '-' || *line == '_')
        {
            test[count] = *line;
            count++;
            line++;
        }
        test[count] = '\0';
        printf("ok test = -%s- et count = -%d-\n", test, count);
        ft_strcpy(pars.pt_we, test);
        printf("test = %s\n", test);
        printf("pars.we = %s \n", pars.pt_we);
    }
    else
    {
        printf("ERROR 12\n");
        exit(0);
    }
    
    return (line);
}

char    *ft_get_we(char *line, t_pars pars)
{
    printf("Dans we *pars.pt_we = %s\n", pars.pt_we);
    line++;
    if (*line == 'E')
    {
        line++;
        while (*line)
        {
            if (ft_isspace((int)*line) == 1)
                line++;
            else if (ft_isdigit((int)*line) == 1 || ft_isalpha((int)*line) == 1)
            {
                ft_putstr("ERREUR WE dans le fichier cub alpha ou .\n");
			    exit(0);
            }
            else if (*line == '.' && *pars.pt_we == '\0')
                line = ft_get_we_data(line, pars);
            else
            {
                printf("ERROR dans WE\n");
                exit(0);
            }
        }
    }
    else
    {
        printf("ERROR dans We pas de E\n");
        exit(0);
    }
    return (line);
}
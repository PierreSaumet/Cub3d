/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*  This file contains  functions:
**  - 'get_str(t_data *data, char *line, char c, char *pt)':    call the right
**  function according to the letter.
**  - 'ft_copy(char *dest, char *src)':     copy the datas into the pointers.
**  - 'ft_malloc(t_data *data, char c, char *line)':    allocate the memory
**  for the pointers from the structure called 's_data'.
**  - 'check_str(char *line)':              check the string et quit the
**  program if it find an error.
*/

static void         check_str(char *line)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    while (line[i])
    {
        if (ft_isspace((int)line[i]) == 1 || ft_isalnum((int)line[i]) == 1
            || line[i] == '/' || line[i] == '-' || line[i] == '_' || line[i] == '.')
        {
            if ((ft_isalnum((int)line[i]) == 1
                    || line[i] == '/' || line[i] == '-' || line[i] == '_'
                    || line[i] == '.') && line[i - 1] == ' ')
                j++;
            i++;
        }
        else
            quit("Texture's adress not valide!\n");
    }
    if (j > 1)
        quit("Texture should have one adress!\n");
}

static void                ft_malloc(t_data *data, char c, char *line)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    while (line[i++])
    {
        if (line[i] == ' ')
            j++;
    }
    if (c == 'N')
        if (!(data->pt_no = malloc(ft_strlen(line) - j + 1)))
            quit("North texture's malloc failed. \n");
    if (c == 'O')
        if (!(data->pt_so = malloc(ft_strlen(line) - j + 1)))
            quit("South texture's malloc failed. \n");
    if (c == 'W')
        if (!(data->pt_we = malloc(ft_strlen(line) - j + 1)))
            quit("West texture's malloc failed. \n");
    if (c == 'E')
        if (!(data->pt_ea = malloc(ft_strlen(line) - j + 1)))
            quit("East texture's malloc failed. \n");
    if (c == 'S')
        if (!(data->pt_sp = malloc(ft_strlen(line) - j + 1)))
            quit("Sprite texture's malloc failed. \n");
}

static void                 ft_copy(char *dest, char *src)
{
    int             i;

    i = 0;
    while (src[i] && ft_isspace((int)src[i]) == 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void                get_str(t_data *data, char *line, char c, char *pt)
{
    int             i;
    int             j;
    
    i = 0;
    j = 0;
    check_str(line);
    if (pt != NULL)
        quit("Texture is already assigned !\n");
    while (ft_isspace((int)line[i]) == 1)
        i++;
    ft_malloc(data, c, &line[i]);
    if (c == 'N')
        ft_copy(data->pt_no, &line[i]);
    if (c == 'O')
        ft_copy(data->pt_so, &line[i]);
    if (c == 'W')
        ft_copy(data->pt_we, &line[i]);
    if (c == 'E')
        ft_copy(data->pt_ea, &line[i]);        
    if (c == 'S')
        ft_copy(data->pt_sp, &line[i]);
}

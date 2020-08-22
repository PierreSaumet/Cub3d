/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*  This file contains 4 functions:
**  - 'get_map(char *argv, t_data *data)':  open GNL, read until the map,
**  allocate the structure called 's_map' with malloc_map.
**  - 'malloc_map(t_data *data, char *buff, int i)':    allocate enough
**  memory then copy the buffer into the char **map2.
**  - 'check_index_map(t_data *data)':      check if the map contains only
**  the right characters by calling the function ft_index.
**  - 'ft_index(t_data *data, char c):      check if 'c' is into the list of
**  authorized characters.
*/

static int                 ft_index(t_data *data, char c)
{
    char            *index;
    int             i;

    index = " 012NSWE";
    i = 0;
    while (index[i])
    {
        if (index[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

void                check_index_map(t_data *data)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    while (i <= data->map_h)
    {
        j = 0;
        while(j < ft_strlen(data->map[i]))
        {
            if (ft_index(data, data->map[i][j]) == 0)
                quit("The map should containonly: - -0-1-2-N-S-W-E.\n");
            else
               j++;
        }
        i++;
    }
}

static int          malloc_map(t_data *data, char *buff, int i)
{
    if (!(data->map[i] = malloc(sizeof(char *) * data->map_w)))
        quit("Can not malloc a line of the map!\n");
    ft_strcpy(data->map[i++], buff);
    free(buff);
    return (i);
}

void                get_map(char *argv, t_data *data)
{
    int             fd;
    char            *buff;
    int             i;
    int             j;

    j = 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    if (fd < 3)
        quit("Can not open the configuration file  (2)\n");
    if (!(data->map = (char **)malloc(sizeof(char *) * (data->map_h + 1))))
        quit("Can not malloc the map!\n");
    while (get_next_line(fd, &buff))
    {
        if (j++ <  data->param_h)
            free(buff);
        else if (!buff[0])
            free(buff);
        else
            i = malloc_map(data, buff, i);
    }
    if (i <= data->map_h)
        i = malloc_map(data, buff, i);
    buff = NULL;
}
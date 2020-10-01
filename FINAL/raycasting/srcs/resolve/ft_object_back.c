/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 2 functions:
**  - 'find_object(t_map *map, t_data *data)':  browse the map, find the
**  object and call find_path to see if the character can reach the object.
**  - 'find_path(int x, int y, t_map *map, t_data *data)':  use recursivity
**  backtracking, to try if the character can reach an object at the limit
**  of the map.
*/

static int             find_path(int x, int y, t_map *map, t_data *data)
{
    if (x == -1 || x == data->map_w ||
            y == -1 || y == data->map_h +1)
        return 0;
    if (x == map->x_ob && y == map->y_ob)
        return 1;
    if (map->map2[y][x] == '1'
            || map->map2[y][x] == 'x'
            || map->map2[y][x] == 'X')
        return 0;
    map->map2[y][x] = 'x';

    if (find_path(x, y - 1, map, data))
        return 1;
    if (find_path(x + 1, y, map, data))
        return 1;
    if (find_path(x, y + 1, map, data))
        return 1;
    if (find_path(x - 1, y, map, data))
        return 1;
    map->map2[y][x] = 'X';
    return 0;
}

void            find_object(t_map *map, t_data *data)
{
    int         i;
    int         j;

    i = 0;
    j = 0;
    while (i < data->map_h + 1)
    {
        j = 0;
        while (j < data->map_w + 1)
        {
            if (map->map2[i][j] == '2')
            {
                map->y_ob = i;
                map->x_ob = j;
                if (find_path(map->x_c, map->y_c, map, data) == 1)
                {
                    if (i == 0 || i == data->map_h || j == 0 || j == data->map_w - 1)
                        quit("ERREUR, le personnage peut sortir\n");
                    cpy_tab(map, data);
                }
                else
                    cpy_tab(map, data);                
            }
            j++;
        }
        i++;
    }
}
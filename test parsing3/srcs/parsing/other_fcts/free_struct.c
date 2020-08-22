/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*
**  This file contains 2 functions:
**  - 'ft_free_struct(t_data *data)':   free all the datas from the structure
**  called 's_data'.
**  - 'ft_free_map(t_map *map, t_data *data)':  free the map from the structure
**  called 's_map'.
*/

void        ft_free_map(t_map *map, t_data *data)
{
    int     i;

    i = 0;
    while (i < data->map_h + 1)
    {
        free(map->map2[i]);
        i++;
    }
    free(map->map2);
    map->map2 = NULL;
}

void        ft_free_struct(t_data *data)
{
    //printf("data.map_h = %d\n", data->map_h);
    int         i;
    
    i = 0;
    while (i < data->map_h + 1)
    {
        //printf("i = %d et %s\n", i, data->map[i]);
        free(data->map[i]);
        i++;
    }
    free(data->map);
    data->map = NULL;
    free(data->pt_no);
    free(data->pt_so);
    free(data->pt_we);
    free(data->pt_ea);
    free(data->pt_sp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
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
**  - 'init_params(t_data *data):   initialize all the parameters needed for
**  the map's parsing from the structure called 's_data'.
**  - 'init_map(t_map *map)':       initialize all the parameters needed for
**  the second map's parsing from the structure called 's_map 
*/

void            init_map(t_map *map)
{
    map->x_c = -1;
    map->y_c = -1;
    map->x_ob = -1;
    map->y_ob = -1;
    map->map2 = NULL;
}

void            init_params(t_data *data)
{
    data->param_h = 0;
    data->map_h = 0;
    data->map_w = 0;
    data->character = 0;
    data->tt_line = 0;
    data->nb_data = 0;
    data->nb_empty = 0;
    data->tt_empty = 0;
    data->rx = 0;
    data->ry = 0;
    data->pt_no = NULL;
    data->pt_so = NULL;
    data->pt_we = NULL;
    data->pt_ea = NULL;
    data->pt_sp = NULL;
    data->fr = -1;
    data->fg = -1;
    data->fb = -1;
    data->cr = -1;
    data->cg = -1;
    data->cb = -1;
    data->map = NULL;
    data->index = " 012NSWE";
    data->c_x = -1;
    data->c_y = -1;
    data->charac = '1';
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*
**  This file contains 3 functions:
**  - 'ft_display_params(t_data *data)':    display all the datas for the
**  parameters.
**  - 'ft_display_map(t_data *data)':   display the saved map.
**  - 'printf_tab(t_map *map, t_data *data)': display the second map.

**              This file need to be remove!!!
*/

void        ft_display_params(t_data *data)
{
    printf("data->map_h = %d\n", data->map_h);
    printf("data->rx = %d\n", data->rx);
    printf("data->ry = %d\n", data->ry);
    printf("data->no = %s\n", data->pt_no);
    printf("data->so = %s\n", data->pt_so);
    printf("data->we = %s\n", data->pt_we);
    printf("data->ea = %s\n", data->pt_ea);
    printf("data->sp = %s\n", data->pt_sp);
    printf("data->fr = %d\n", data->fr);
    printf("data->fg = %d\n", data->fg);
    printf("data->fb = %d\n", data->fb);
    printf("data->cr = %d\n", data->cr);
    printf("data->cg = %d\n", data->cg);
    printf("data->cb = %d\n", data->cb);
    printf("\n\ndata->nb_data = %d\n", data->nb_data);
    printf("data->param_h = %d\n", data->param_h);
    printf("data->map_h = %d\n", data->map_h);
    printf("data->map_w = %d\n", data->map_w);
    printf("data->tt_line = %d\n", data->tt_line);
    printf("data->tt_empty = %d\n", data->tt_empty);
    printf("data->nb_empty = %d\n", data->nb_empty);
}

void        ft_display_map(t_data *data)
{
    int     i;
    i = 0;
    
    while (i <= data->map_h)
    {
        printf("MAP %d\t%s\n", i, data->map[i]);
        i++;
    }
}

void            printf_tab(t_map *map, t_data *data)
{
    int         i;

    i = 0;
    while (i <= data->map_h)
    {
        printf("map = -%s-\n", map->map2[i]);
        i++;
    }
}
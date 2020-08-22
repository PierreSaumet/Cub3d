/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*  This file contains 2 functions:
**  - 'change_sp_map(t_data *data)':    browse the buffer and call change_sp.
**  - 'change_sp(t_data *data, int i, int j)':  change the space character
**  into a '1' etc.
*/
int                change_sp(t_data *data, int i, int j)
{
    if (data->map[i][j] == ' ')
        data->map[i][j] = '1';
    else if (data->map[i][j] == '\n')
        data->map[i][j] = '1';
    else if (data->map[i][j] == '\0')
    {
        data->map[i][j] = '1';
        while(j < data->map_w )
        {
            data->map[i][j] = '1';
            j++;
        }
        data->map[i][data->map_w] = '\0';
        return (j);
    }
    else if (data->map[i][j] == '\t')
        data->map[i][j] = '1';
    return (j);
}

void                change_sp_map(t_data *data)
{
    int             i;
    int             j;

    i = 0;
    j = 0; 
    while (i <= data->map_h)
    {
        j = 0;
        while(j < data->map_w)
        {
            j = change_sp(data, i, j);
            if (j == data->map_w )
                data->map[i][j] = '\0';
            j++;
        }
        i++;
    }
}
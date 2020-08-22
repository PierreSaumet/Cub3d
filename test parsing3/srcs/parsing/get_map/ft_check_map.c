/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*  This file contains 5 functions:
**  - 'ft_check_map(t_data *data)':     this function is the main function
**  to check if the map is correct. Call all others functions.
**  - 'check_f_l(t_data *data, int line)':  check the first or the last line
**  if there is something different fromn '1'/'2'/' ', quit programme.
**  - 'check_last_c(t_data *data)' && 'check_first_c(t_data *data)':
**  Do te same job as 'check_f_l' but for the column.
**  - 'check_carac(t_data *data)':      check if the character is present.
*/

void         check_f_l(t_data *data, int line)
{
    int     i;

    i = 0;
    if (line == 1)
    {
        while (i < ft_strlen(data->map[0]))
        {
            if (data->map[0][i] != '1' && data->map[0][i] != ' '
                    && data->map[0][i] != '2')
                quit("The map is not valid! (fl)\n");
            i++;
        }
    }
    else
    {
        while (i < ft_strlen(data->map[data->map_h]))
        {
            if (data->map[data->map_h][i] != '1' && data->map[data->map_h][i] != ' '
                    && data->map[data->map_h][i] != '2')
                quit("The map is not valid! (ll)\n");
            i++;
        }
    }
}

void            check_carac(t_data *data)
{
    int         i;
    int         j;
    int         k;
    char        *charac;

    i = 0;
    j = 0;
    k = 0;
    charac = "NSEW";
    while (i <= data->map_h)
    {
        j = 0;
        while (j < data->map_w)
        {
            k = 0;
            while (charac[k])
            {
                if (charac[k] == data->map[i][j])
                    data->character++;
                k++;
            }
            j++;
        }
        i++;
    }
}

void            check_first_c(t_data *data)
{
    int         i;

    i = 0;
    while (i <= data->map_h)
    {
        if (data->map[i][0] == '0')
            quit("The map is not valid, all zero should be around by '1' (fc).\n");
        if (data->map[i][0] == 'N' || data->map[i][0] == 'S'
                || data->map[i][0] == 'E' || data->map[i][0] == 'W')
            quit("The map is not valid, the charactor can't start on border (fc).\n");
        i++;
    }
}


void            check_last_c(t_data *data)
{
    int         i;

    i = 0;
    while (i <= data->map_h)
    {
        if (data->map[i][data->map_w - 1] == '0')
            quit("The map is not valid, all zero should be around by '1' (lc).\n");
        if (data->map[i][data->map_w - 1] == 'N' || data->map[i][data->map_w - 1] == 'S'
                || data->map[i][data->map_w - 1] == 'E' || data->map[i][data->map_w - 1] == 'W')
            quit("The map is not valid, the charactor can't stop on border (lc).\n");
        i++;
    }
}


void            ft_check_map(t_data *data)
{
    check_f_l(data, 1);
    check_f_l(data, 2);
    check_first_c(data);
    check_last_c(data);
    check_carac(data);
    if (data->character != 1)
        quit("Map: need only one character.\n");
    printf("-----------------------------------\n\t\tMAP PARFAITE\n");
}
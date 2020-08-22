/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cube3d.h"

/*  This file contains 2 functions:
**  - 'get_r(t_data *data, char *line)':    call check_r_line and get the
**  number with ft_atoi().
**  - 'check_r_line(t_data *data, char *line)': check if the line is only
**  composed with letters.
*/

static void                check_r_line(t_data *data, char *line)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    if (data->rx != 0 && data->ry != 0)
        quit("Resolution has already been assigned!\n");
    while (line[i])
    {
        if (ft_isspace((int)line[i]) == 1 
                || (line[i] >= '0' && line[i] <= '9'))
        {
            if ((line[i] >= '0' && line[i] <= '9') && line[i - 1] == ' ')
                j++;
            i++;
        }
        else
            quit("Resolution: There should be only number...\n"); 
    }
    if (j > 2)
        quit("Resolution : There sould be only 2 numbers! \n");
}

void                get_r(t_data *data, char *line)
{
    int             i;

    i = 0;
    check_r_line(data, line);
    data->rx = ft_atoi(line);
    while (ft_isspace((int)line[i]) == 1)
        i++;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    data->ry = ft_atoi(&line[i]);
}
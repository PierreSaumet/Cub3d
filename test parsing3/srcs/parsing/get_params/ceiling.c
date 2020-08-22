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

/*  This file contains 5 functions:
**  - 'get_floor(t_data *data, char *line)':    call check_f_or_c() to verify
**  the line, and call get_digit_f() to get the datas.
**  - 'get_digit_f(t_data *data, char *line, int i, int ind)':  get the datas
**  using ft_atoi and return the index of the line.
**  - 'get_ceilling(t_data *data, char *line)': call check_f_or_c() to verify
**  the line, and call get_digit_c() to get the datas
**  - 'get_digit_c(t_data *data, char *line, int i, int ind)':  get the datas
**  using ft_atoi and return the index of the line.
**  - 'check_f_or_c(t_data *data, char *line)':     check if the line contains
**  only number, space and ','.
*/

static void     check_f_or_c(t_data *data, char *line)
{
    int         i;
    int         j;
    int         k;        

    i = 0;
    j = 0;
    k = 0;
    while (line[i])
    {
        if (ft_isspace((int)line[i]) || ft_isdigit((int)line[i])
                || line[i] == ',')
        {
            if (ft_isdigit((int)line[i]) && (line[i - 1] == ' '
                    || line[i -1] == ','))
                j++;
            if  (line[i] == ',')
                k++;
            if (j < k)
                quit("Floor or Ceiling: first a number then ','\n");
            i++;
        }
        else
            quit("Floor or Ceiling: Only numbers and ','! \n");
    }
    if (j != 3 || k != 2)
        quit("Floor or Ceiling, only 3 numbers and two ','. \n"); 
}


static int      get_digit_c(t_data *data, char *line, int i, int ind)
{
    if (ind == 1)
    {
        data->cr =ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
           i++;
        return (i);
    }
    else if (ind == 2)
    {
        data->cg = ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
            i++;
        return (i);
    }
    else if (ind == 3)
    {
        data->cb = ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
            i++;
        return (i);
    }
    return (i);
}

void            get_ceilling(t_data *data, char *line)
{
    int         i;

    i = 0;
    check_f_or_c(data, line);
    if (data->cr != -1 && data->cb != -1 && data->cg != -1)
        quit("Ceiling already assigned\n");
    while (line[i] && line)
    {
        if (line[i] == ' ' || line[i] == ',')
            i++;
        else if (ft_isdigit((int)line[i]))
        {
            if (data->cr == -1)
                i = get_digit_c(data, line, i, 1);
            else if (data->cg == -1)
                i = get_digit_c(data, line, i, 2);
            else
                i = get_digit_c(data, line, i, 3);
        }
        else
            i++;
    }
}

static int      get_digit_f(t_data *data, char *line, int i, int ind)
{
    if (ind == 1)
    {
        data->fr =ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
           i++;
        return (i);
    }
    else if (ind == 2)
    {
        data->fg = ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
            i++;
        return (i);
    }
    else if (ind == 3)
    {
        data->fb = ft_atoi(&line[i]);
        while (ft_isdigit((int)line[i]))
            i++;
        return (i);
    }
    return (i);
}

void            get_floor(t_data *data, char *line)
{
    int         i;

    i = 0;
    check_f_or_c(data, line);
    if (data->fr != -1 && data->fb != -1 && data->fg != -1)
        quit("Floor already assigned\n");
    while (line[i] && line)
    {
        if (line[i] == ' ' || line[i] == ',')
            i++;
        else if (ft_isdigit((int)line[i]))
        {
            if (data->fr == -1)
                i = get_digit_f(data, line, i, 1);
            else if (data->fg == -1)
                i = get_digit_f(data, line, i, 2);
            else
                i = get_digit_f(data, line, i, 3);
        }
    }
}
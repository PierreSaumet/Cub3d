/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/headers/cube3d.h"

/*
**  This file contains 1 function:
**  - 'check_arg(char *argv)':  it checks if the file argument is correct.
*/

void                check_arg(char *argv)
{
    int             i;

    i = 0;
    while (argv[i])
    {
        if (argv[i] == '.')
        {
            if (argv[i + 1] == 'c' && argv[i + 2] == 'u'
                    && argv[i + 3] == 'b' && argv[i + 4] == '\0')
                return ;
        }
        i++;
    }
    quit("Need one argument with the extension '.cub'\n");
}
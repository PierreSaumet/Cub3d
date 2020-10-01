/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/07/22 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 2 functions:
**  - 'quit(char *error_msg)':  get a string (error message), use ft_puterror
**  and eixt the program.
**  - 'ft_puterror(char *str)': display the string.
*/

static void             ft_puterror(char *str)
{
    int                 i;
    
    i = 0;
    if (!str)
        return ;
    write(1, "ERROR !\n\t", 9);
    write(1, str, strlen(str));
}

void                    quit(char *error_msg)
{
    if (error_msg)
        ft_puterror(error_msg);
    exit(1);
}
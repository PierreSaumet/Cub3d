/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:34:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:51:43 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"
#include "../headers/get_next_line.h"
#include "../headers/libft.h"
#include <stdio.h>

void        ft_init_t_pars(t_pars *val)
{
    int     i;
    char    c;

    i = 0;
    c = 'Q';
    val->pt_rx = &i;
    val->pt_ry = &i;
    val->pt_fr = &i;
    val->pt_fg = &i;
    val->pt_fb = &i;
    val->pt_cr = &i;
    val->pt_cg = &i;
    val->pt_cb = &i;
    val->pt_no = &c;
    val->pt_so = &c;
    val->pt_we = &c;
    val->pt_ea = &c;
    val->pt_sprite = &c;
}
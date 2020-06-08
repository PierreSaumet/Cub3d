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
    val->rx = 0;
    val->pt_rx = &val->rx;
    val->ry = 0;
    val->pt_ry = &val->ry;

    val->fr = 0;
    val->pt_fr = &val->fr;
    val->fg = 0;
    val->pt_fg = &val->fg;
    val->fb = 0;
    val->pt_fb = &val->fb;

    val->cr = 0;
    val->pt_cr = &val->cr;
    val->cg = 0;
    val->pt_cg = &val->cg;
    val->cb = 0;
    val->pt_cb = &val->cb;

    val->no[0] = '\0';
    val->pt_no = val->no;

    val->so[0] = '\0';
    val->pt_so = val->so;

    val->we[0] = '\0';
    val->pt_we = val->we;

    val->ea[0] = '\0';
    val->pt_ea = val->ea;

    val->s[0] = '\0';
    val->pt_s = val->s;
    /*
    val->pt_cr = &i;
    val->pt_cg = &i;
    val->pt_cb = &i;
    val->pt_no = &c;
    val->pt_so = &c;
    val->pt_we = &c;
    val->pt_ea = &c;
    val->pt_sprite = &c;*/
}
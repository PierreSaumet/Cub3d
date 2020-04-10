/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:04:22 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 17:54:39 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
/*
**  This structure will contains all the data used for creation of the map.
**  You will find the resolution, different paths, sprite texture, floor
**  and ceiling.
*/

typedef struct      s_pars
{
    int             *pt_rx;
    int             *pt_ry;
    char            *pt_no;
    char            *pt_so;
    char            *pt_we;
    char            *pt_ea;
    char            *pt_sprite;
    int             *pt_fr;
    int             *pt_fg;
    int             *pt_fb;
    int             *pt_cr;
    int             *pt_cg;
    int             *pt_cb;
}                   t_pars;

void		ft_parsing(char *argv);
int			ft_check(char *argv);
void        ft_init_t_pars(t_pars *val);
#endif

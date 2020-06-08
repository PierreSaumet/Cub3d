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
    int             rx;
    int             *pt_rx;
    int             ry;
    int             *pt_ry;
    char            no[124];
    char            *pt_no;
    char            so[124];
    char            *pt_so;
    char            we[124];
    char            *pt_we;
    char            ea[124];
    char            *pt_ea;
    char            s[124];
    char            *pt_s;
    int             fr;
    int             *pt_fr;
    int             fg;
    int             *pt_fg;
    int             fb;
    int             *pt_fb;
    int             cr;
    int             *pt_cr;
    int             cg;
    int             *pt_cg;
    int             cb;
    int             *pt_cb;
}                   t_pars;

void		ft_parsing(char *argv);
int         ft_get_data(char *line, t_pars pars);

int			ft_check_arg(char *argv);

void        ft_init_t_pars(t_pars *val);

char	    *ft_get_r(char *line, t_pars pars);
char	    *ft_get_rdata(char *line, t_pars pars);
char	    *ft_get_f(char *line, t_pars pars);
char	    *ft_get_fdata(char *line, t_pars pars);
char	    *ft_get_c(char *line, t_pars pars);
char	    *ft_get_cdata(char *line, t_pars pars);

char        *ft_get_no(char *line, t_pars pars);
char        *ft_get_no_data(char *line, t_pars pars);
#endif

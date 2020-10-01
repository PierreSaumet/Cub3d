/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parsingstruct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 3 functions all used to initialize the structures.
**  - 'ft_init_dda(t_dda *dda_val)': put 0 to the variables used for DDA,
**  - 'ft_init_mvt(t_parsing *parsing_val)':    put 0 to the variables for
**  the movements.
**  - 'ft_init_parsing(t_parsing *parsing_val)': first initialization.
**  the variables will change right after the call of the function.
*/

void			ft_init_dda(t_dda *dda_val)
{
	dda_val->camerax = 0;
	dda_val->raydirx = 0;
	dda_val->raydiry = 0;
	dda_val->mapx = 0;
	dda_val->mapy = 0;
	dda_val->sidedistx = 0;
	dda_val->sidedisty = 0;
	dda_val->deltadistx = 0;
	dda_val->deltadisty = 0;
	dda_val->perpwalldist = 0;
	dda_val->lineheight = 0;
	dda_val->stepx = 0;
	dda_val->stepy = 0;
	dda_val->hit = 0;
	dda_val->side = 0;
	dda_val->drawstart = 0;
	dda_val->drawend = 0;
	dda_val->wallx = 0;
}

void			ft_init_mvt(t_parsing *parsing_val)
{
	parsing_val->mvt.forward = 0;
	parsing_val->mvt.backward = 0;
	parsing_val->mvt.left = 0;
	parsing_val->mvt.right = 0;
	parsing_val->mvt.cam_l = 0;
	parsing_val->mvt.cam_r = 0;
}

void			ft_init_parsing(t_parsing *parsing_val)
{
	double		radian;

	radian = (60 / 2) * (3.14159275 / 180);
	parsing_val->screenw = 640;
	parsing_val->screenh = 480;
	parsing_val->maph = 24;
	parsing_val->mapw = 24;
	parsing_val->posx = (double)22 + 0.5;
	parsing_val->posy = (double)12 + 0.5;
	parsing_val->dirx = -1;
	parsing_val->diry = 0;
	parsing_val->planex = (parsing_val->diry * tan(radian / 2.0));
	parsing_val->planey = -(parsing_val->dirx * tan(radian / 2.0));
	parsing_val->refresh = 0;
	parsing_val->floor = 0xDC6400;
	parsing_val->ceiling = 0xFF1E00;
	parsing_val->nsp = 0;
	parsing_val->map = NULL;
}

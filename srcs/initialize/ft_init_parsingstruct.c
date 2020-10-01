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
**  - 'ft_init_dda(dda_t *dda_val)': put 0 to the variables used for DDA,
**  - 'ft_init_mvt(parsing_t *parsing_val)':    put 0 to the variables for
**  the movements.
**  - 'ft_init_parsing(parsing_t *parsing_val)': first initialization.
**  the variables will change right after the call of the function.
*/

void			ft_init_dda(dda_t *dda_val)
{
	dda_val->cameraX = 0;
	dda_val->rayDirX = 0;
	dda_val->rayDirY = 0;
	dda_val->mapX = 0;
	dda_val->mapY = 0;
	dda_val->sideDistX = 0;
	dda_val->sideDistY = 0;
	dda_val->deltaDistX = 0;
	dda_val->deltaDistY = 0;
	dda_val->perpWallDist = 0;
	dda_val->lineHeight = 0;
	dda_val->stepX = 0;
	dda_val->stepY = 0;
	dda_val->hit = 0;
	dda_val->side = 0;
	dda_val->drawstart = 0;
	dda_val->drawend = 0;
	dda_val->wallx = 0;
}

void			ft_init_mvt(parsing_t *parsing_val)
{
	parsing_val->mvt.forward = 0;
	parsing_val->mvt.backward = 0;
	parsing_val->mvt.left = 0;
	parsing_val->mvt.right = 0;
	parsing_val->mvt.cam_l = 0;
	parsing_val->mvt.cam_r = 0;
}

void			ft_init_parsing(parsing_t *parsing_val)
{
	double		radian;

	radian = (60 / 2) * (3.14159275 / 180);
	parsing_val->screenW = 640;
	parsing_val->screenH = 480;
	parsing_val->mapH = 24;
	parsing_val->mapW = 24;
	parsing_val->posX = (double)22 + 0.5;
	parsing_val->posY = (double)12 + 0.5;
	parsing_val->dirX = -1;
	parsing_val->dirY = 0;
	parsing_val->planeX = (parsing_val->dirY * tan(radian / 2.0));
	parsing_val->planeY = -(parsing_val->dirX * tan(radian / 2.0));
	parsing_val->refresh = 0;
	parsing_val->floor = 0xDC6400;
	parsing_val->ceiling = 0xFF1E00;
	parsing_val->nsp = 0;
	parsing_val->map = NULL;
}

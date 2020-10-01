/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 5 functions needed for the Digital Differential Analysis.
**  - 'ft_init_raycast(parsing_t *pars_val, int x)':    init all the variables.
**  - 'ft_put_txt_buff(parsing_t *p_val, int x)':   choose the right texture,
**  then draw ceileing, wall and floor.
**  - 'ft_calc_perp_draw(parsing_t *pars_val, double *z_buff)': calcul
**  the perpendicalar wall (eyes fish).
**  - 'ft_dda(parsing_t *pars_val)':    do the dda.
**  - 'ft_calc_stepx_y(parsing_t *pars_val)':   find the stepx and y with the
**  direction.
*/

void			ft_put_txt_buff(parsing_t *p_val, int x)
{
	texture_t	texture;
	int			i;

	i = 0;
	texture = ft_choose_texture(p_val->dda.side, p_val);
	ft_draw_ceiling(p_val, &i, x);
	ft_draw_wall(p_val, texture, x, &i);
	ft_draw_floor(p_val, &i, x);
}

void			ft_calc_perp_draw(parsing_t *pars_val, double *z_buff)
{
	if (pars_val->dda.side == NORTH || pars_val->dda.side == SOUTH)
		pars_val->dda.perpWallDist = (pars_val->dda.mapX - pars_val->posX +
			(1 - pars_val->dda.stepX) / 2) / pars_val->dda.rayDirX;
	else
		pars_val->dda.perpWallDist = (pars_val->dda.mapY - pars_val->posY +
			(1 - pars_val->dda.stepY) / 2) / pars_val->dda.rayDirY;
	*z_buff = pars_val->dda.perpWallDist;
	pars_val->dda.lineHeight = (int)(pars_val->screenH
		/ pars_val->dda.perpWallDist);
	pars_val->dda.drawstart = -pars_val->dda.lineHeight
		/ 2 + pars_val->screenH / 2;
	if (pars_val->dda.drawstart < 0)
		pars_val->dda.drawstart = 0;
	pars_val->dda.drawend = pars_val->dda.lineHeight / 2 + pars_val->screenH
		/ 2;
	if (pars_val->dda.drawend >= pars_val->screenH)
		pars_val->dda.drawend = pars_val->screenH - 1;
	if (pars_val->dda.side == NORTH || pars_val->dda.side == SOUTH)
		pars_val->dda.wallx = pars_val->posY + pars_val->dda.perpWallDist
			* pars_val->dda.rayDirY;
	if (pars_val->dda.side == EAST || pars_val->dda.side == WEST)
		pars_val->dda.wallx = pars_val->posX + pars_val->dda.perpWallDist
			* pars_val->dda.rayDirX;
	pars_val->dda.wallx -= floor(pars_val->dda.wallx);
}

void			ft_dda(parsing_t *pars_val)
{
	pars_val->dda.hit = 0;
	while (pars_val->dda.hit == 0)
	{
		if (pars_val->dda.sideDistX < pars_val->dda.sideDistY)
		{
			pars_val->dda.sideDistX += pars_val->dda.deltaDistX;
			pars_val->dda.mapX += pars_val->dda.stepX;
			pars_val->dda.side = pars_val->dda.rayDirX < 0 ? NORTH : SOUTH;
		}
		else
		{
			pars_val->dda.sideDistY += pars_val->dda.deltaDistY;
			pars_val->dda.mapY += pars_val->dda.stepY;
			pars_val->dda.side = pars_val->dda.rayDirY < 0 ? EAST : WEST;
		}
		if (pars_val->map[pars_val->dda.mapX][pars_val->dda.mapY] == '1')
			pars_val->dda.hit = 1;
	}
}

void			ft_calc_stepx_y(parsing_t *pars_val)
{
	if (pars_val->dda.rayDirX < 0)
	{
		pars_val->dda.stepX = -1;
		pars_val->dda.sideDistX = (pars_val->posX - pars_val->dda.mapX)
			* pars_val->dda.deltaDistX;
	}
	else
	{
		pars_val->dda.stepX = 1;
		pars_val->dda.sideDistX = (pars_val->dda.mapX + 1.0
			- pars_val->posX) * pars_val->dda.deltaDistX;
	}
	if (pars_val->dda.rayDirY < 0)
	{
		pars_val->dda.stepY = -1;
		pars_val->dda.sideDistY = (pars_val->posY - pars_val->dda.mapY)
			* pars_val->dda.deltaDistY;
	}
	else
	{
		pars_val->dda.stepY = 1;
		pars_val->dda.sideDistY = (pars_val->dda.mapY + 1.0
			- pars_val->posY) * pars_val->dda.deltaDistY;
	}
}

void			ft_init_raycast(parsing_t *pars_val, int x)
{
	pars_val->dda.cameraX = 2 * x / (double)pars_val->screenW - 1;
	pars_val->dda.rayDirX = pars_val->dirX + pars_val->planeX
		* pars_val->dda.cameraX;
	pars_val->dda.rayDirY = pars_val->dirY + pars_val->planeY
		* pars_val->dda.cameraX;
	pars_val->dda.mapX = (int)pars_val->posX;
	pars_val->dda.mapY = (int)pars_val->posY;
	pars_val->dda.deltaDistX = fabs(1 / pars_val->dda.rayDirX);
	pars_val->dda.deltaDistY = fabs(1 / pars_val->dda.rayDirY);
}

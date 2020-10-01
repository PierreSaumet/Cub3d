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
**  - 'ft_init_raycast(t_parsing *pars_val, int x)':    init all the variables.
**  - 'ft_put_txt_buff(t_parsing *p_val, int x)':   choose the right texture,
**  then draw ceileing, wall and floor.
**  - 'ft_calc_perp_draw(t_parsing *pars_val, double *z_buff)': calcul
**  the perpendicalar wall (eyes fish).
**  - 'ft_dda(t_parsing *pars_val)':    do the dda.
**  - 'ft_calc_stepx_y(t_parsing *pars_val)':   find the stepx and y with the
**  direction.
*/

void			ft_put_txt_buff(t_parsing *p_val, int x)
{
	t_texture	texture;
	int			i;

	i = 0;
	texture = ft_choose_texture(p_val->dda.side, p_val);
	ft_draw_ceiling(p_val, &i, x);
	ft_draw_wall(p_val, texture, x, &i);
	ft_draw_floor(p_val, &i, x);
}

void			ft_calc_perp_draw(t_parsing *pars_val, double *z_buff)
{
	if (pars_val->dda.side == NORTH || pars_val->dda.side == SOUTH)
		pars_val->dda.perpwalldist = (pars_val->dda.mapx - pars_val->posx +
			(1 - pars_val->dda.stepx) / 2) / pars_val->dda.raydirx;
	else
		pars_val->dda.perpwalldist = (pars_val->dda.mapy - pars_val->posy +
			(1 - pars_val->dda.stepy) / 2) / pars_val->dda.raydiry;
	*z_buff = pars_val->dda.perpwalldist;
	pars_val->dda.lineheight = (int)(pars_val->screenh
		/ pars_val->dda.perpwalldist);
	pars_val->dda.drawstart = -pars_val->dda.lineheight
		/ 2 + pars_val->screenh / 2;
	if (pars_val->dda.drawstart < 0)
		pars_val->dda.drawstart = 0;
	pars_val->dda.drawend = pars_val->dda.lineheight / 2 + pars_val->screenh
		/ 2;
	if (pars_val->dda.drawend >= pars_val->screenh)
		pars_val->dda.drawend = pars_val->screenh - 1;
	if (pars_val->dda.side == NORTH || pars_val->dda.side == SOUTH)
		pars_val->dda.wallx = pars_val->posy + pars_val->dda.perpwalldist
			* pars_val->dda.raydiry;
	if (pars_val->dda.side == EAST || pars_val->dda.side == WEST)
		pars_val->dda.wallx = pars_val->posx + pars_val->dda.perpwalldist
			* pars_val->dda.raydirx;
	pars_val->dda.wallx -= floor(pars_val->dda.wallx);
}

void			ft_dda(t_parsing *pars_val)
{
	pars_val->dda.hit = 0;
	while (pars_val->dda.hit == 0)
	{
		if (pars_val->dda.sidedistx < pars_val->dda.sidedisty)
		{
			pars_val->dda.sidedistx += pars_val->dda.deltadistx;
			pars_val->dda.mapx += pars_val->dda.stepx;
			pars_val->dda.side = pars_val->dda.raydirx < 0 ? NORTH : SOUTH;
		}
		else
		{
			pars_val->dda.sidedisty += pars_val->dda.deltadisty;
			pars_val->dda.mapy += pars_val->dda.stepy;
			pars_val->dda.side = pars_val->dda.raydiry < 0 ? EAST : WEST;
		}
		if (pars_val->map[pars_val->dda.mapx][pars_val->dda.mapy] == '1')
			pars_val->dda.hit = 1;
	}
}

void			ft_calc_stepx_y(t_parsing *pars_val)
{
	if (pars_val->dda.raydirx < 0)
	{
		pars_val->dda.stepx = -1;
		pars_val->dda.sidedistx = (pars_val->posx - pars_val->dda.mapx)
			* pars_val->dda.deltadistx;
	}
	else
	{
		pars_val->dda.stepx = 1;
		pars_val->dda.sidedistx = (pars_val->dda.mapx + 1.0
			- pars_val->posx) * pars_val->dda.deltadistx;
	}
	if (pars_val->dda.raydiry < 0)
	{
		pars_val->dda.stepy = -1;
		pars_val->dda.sidedisty = (pars_val->posy - pars_val->dda.mapy)
			* pars_val->dda.deltadisty;
	}
	else
	{
		pars_val->dda.stepy = 1;
		pars_val->dda.sidedisty = (pars_val->dda.mapy + 1.0
			- pars_val->posy) * pars_val->dda.deltadisty;
	}
}

void			ft_init_raycast(t_parsing *pars_val, int x)
{
	pars_val->dda.camerax = 2 * x / (double)pars_val->screenw - 1;
	pars_val->dda.raydirx = pars_val->dirx + pars_val->planex
		* pars_val->dda.camerax;
	pars_val->dda.raydiry = pars_val->diry + pars_val->planey
		* pars_val->dda.camerax;
	pars_val->dda.mapx = (int)pars_val->posx;
	pars_val->dda.mapy = (int)pars_val->posy;
	pars_val->dda.deltadistx = fabs(1 / pars_val->dda.raydirx);
	pars_val->dda.deltadisty = fabs(1 / pars_val->dda.raydiry);
}

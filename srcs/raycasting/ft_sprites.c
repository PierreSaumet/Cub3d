/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 5 functions:
**  - 'ft_draw_sprite(t_parsing *p_val, double *z_buff)':   main function to
**  create sprite.
**  - 'ft_sp_dist(t_parsing *p_val)':   Calculate the distance between the
**  sprite and character.
**  - 'ft_sort_sp(t_parsing *p_val)':   Sort the sprites by distance.
**  - 'ft_sp_calcul(t_parsing *p_val, t_sp_params *sp, double sp_x,
**      double sp_y)':  Made the calculs for displaying the sprites.
**  - 'ft_display_sprite(t_parsing *p_val, t_sp_params *sp, double *s_buff)':
**  find the right color and then display the sprite.
*/

static void			ft_sp_dist(t_parsing *p_val)
{
	int				i;

	i = 0;
	while (i < p_val->nsp)
	{
		p_val->ssp[i].sp_dist = ((p_val->posx - p_val->ssp[i].sp_x) *
				(p_val->posx - p_val->ssp[i].sp_x) + (p_val->posy -
				p_val->ssp[i].sp_y) * (p_val->posy - p_val->ssp[i].sp_y));
		i++;
	}
}

static void			ft_sort_sp(t_parsing *p_val)
{
	int				i;
	t_sprite		tmp;

	i = 0;
	while (i < p_val->nsp - 1)
	{
		if (p_val->ssp[i].sp_dist < p_val->ssp[i + 1].sp_dist)
		{
			tmp = p_val->ssp[i];
			p_val->ssp[i] = p_val->ssp[i + 1];
			p_val->ssp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void			ft_sp_calcul(t_parsing *p_val, t_sp_params *sp,
		double sp_x, double sp_y)
{
	sp_x = sp_x - p_val->posx + 0.5;
	sp_y = sp_y - p_val->posy + 0.5;
	sp->invdet = 1.0 / (p_val->planex * p_val->diry - p_val->dirx
		* p_val->planey);
	sp->transformx = sp->invdet * (p_val->diry * sp_x - p_val->dirx *
			sp_y);
	sp->transformy = sp->invdet * (-p_val->planey * sp_x + p_val->planex *
			sp_y);
	sp->screenx = (int)((p_val->screenw / 2) * (1 + sp->transformx /
			sp->transformy));
	sp->sp_h = abs((int)(p_val->screenh / (sp->transformy)));
	sp->drawstarty = -sp->sp_h / 2 + p_val->screenh / 2;
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->sp_h / 2 + p_val->screenh / 2;
	if (sp->drawendy >= p_val->screenh)
		sp->drawendy = p_val->screenh - 1;
	sp->sp_w = abs((int)(p_val->screenh / (sp->transformy)));
	sp->drawstartx = -sp->sp_w / 2 + sp->screenx;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->sp_w / 2 + sp->screenx;
	if (sp->drawendx >= p_val->screenw)
		sp->drawendx = p_val->screenw - 1;
}

static void			ft_display_sprite(t_parsing *p_val, t_sp_params *sp,
		double *s_buff)
{
	int				i;
	int				color;

	i = 0;
	color = 0;
	while (sp->drawstartx < sp->drawendx)
	{
		sp->texx = (int)ft_get_texx(sp, p_val->sp_texture.w);
		i = sp->drawstarty;
		if (sp->transformy > 0 && sp->drawstartx > 0 && sp->drawstartx
				< p_val->screenw && sp->transformy < s_buff[sp->drawstartx])
		{
			while (i < sp->drawendy)
			{
				color = p_val->sp_texture.img[p_val->sp_texture.w
					* ft_get_texy(p_val, sp, i) + sp->texx];
				if (color != 0)
					ft_my_mlx_pixel_put(p_val, sp->drawstartx, i, color);
				i++;
			}
		}
		sp->drawstartx++;
	}
}

void				ft_draw_sprite(t_parsing *p_val, double *z_buff)
{
	int				i;
	t_sp_params		sp;

	i = 0;
	ft_sp_dist(p_val);
	ft_sort_sp(p_val);
	while (i < p_val->nsp)
	{
		ft_sp_calcul(p_val, &sp, p_val->ssp[i].sp_x, p_val->ssp[i].sp_y);
		ft_display_sprite(p_val, &sp, z_buff);
		i++;
	}
}

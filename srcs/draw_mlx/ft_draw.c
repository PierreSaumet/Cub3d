/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 4 functions:
**  - 'ft_choose_texture(int i, t_parsing *p_val)': return the right texture
**  to display.
**  - 'ft_draw_ceiling(t_parsing *p_val, int *i, int x)':   it will draw the
**  ceiling. Starts from zero and stop when the wall starts.
**  - 'ft_draw_floor(t_parsing *p_val, int *i, int x)': it will draw the floor.
**  Starts from the end of the wall to the end of screen.
**  - 'ft_draw_wall(t_parsing *p_val, t_texture text, int x, int *i)':
**  This function will display all the wall. Uses raycasting and DDA.
*/

t_texture		ft_choose_texture(int i, t_parsing *p_val)
{
	if (i == 1)
		return (p_val->n_texture);
	if (i == 2)
		return (p_val->s_texture);
	if (i == 3)
		return (p_val->w_texture);
	if (i == 4)
		return (p_val->e_texture);
	return (p_val->n_texture);
}

void			ft_draw_ceiling(t_parsing *p_val, int *i, int x)
{
	while (*i < p_val->dda.drawstart)
	{
		ft_my_mlx_pixel_put(p_val, x, *i, p_val->ceiling);
		(*i)++;
	}
}

void			ft_draw_floor(t_parsing *p_val, int *i, int x)
{
	while (*i < p_val->screenh && *i >= p_val->dda.drawend)
	{
		ft_my_mlx_pixel_put(p_val, x, *i, p_val->floor);
		(*i)++;
	}
}

void			ft_draw_wall(t_parsing *p_val, t_texture text, int x, int *i)
{
	int			texx;
	int			texy;
	double		texpos;
	double		step;
	int			color;

	texx = (int)(p_val->dda.wallx * (double)text.w);
	if ((p_val->dda.side == NORTH || p_val->dda.side == SOUTH)
			&& p_val->dda.raydirx > 0)
		texx = (double)text.w - texx - 1;
	else if ((p_val->dda.side == EAST || p_val->dda.side == WEST)
			&& p_val->dda.raydiry < 0)
		texx = (double)text.w - texx - 1;
	step = 1.0 * text.h / p_val->dda.lineheight;
	texpos = (p_val->dda.drawstart - p_val->screenh / 2 +
			p_val->dda.lineheight / 2) * step;
	*i = p_val->dda.drawstart;
	while ((*i)++ < p_val->dda.drawend)
	{
		texy = (int)texpos & (text.h - 1);
		texpos += step;
		color = mlx_get_color_value(p_val->mlx_val.mlx_ptr,
			(int)(text.img[text.h * texy + texx]));
		ft_my_mlx_pixel_put(p_val, x, *i, color);
	}
}

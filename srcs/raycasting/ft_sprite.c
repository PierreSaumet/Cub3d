/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
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
**  - 'ft_get_location_sp(parsing_t *p_val)':   Get the location of all sprites
**  - 'ft_init_sprite(parsing_t *p_val)':   Count the number of sprites, and
**  malloc the right size of the structure's sprite.
**  - 'ft_get_texx(sp_params_t *sp_p, int w)':  return the location of
**  the texx.
** - ' ft_get_texy(parsing_t *p_val, sp_params_t *sp, int j)':  return the
**  location ofthe texy.
*/

static void		ft_get_location_sp(parsing_t *p_val)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	j = 0;
	x = 0;
	while (i < p_val->mapH)
	{
		j = 0;
		while (j < (p_val->mapW - 1))
		{
			if (p_val->map[i][j] == '2')
			{
				(p_val->ssp)[x].sp_x = i;
				(p_val->ssp)[x].sp_y = j;
				x++;
			}
			j++;
		}
		i++;
	}
}

void			ft_init_sprite(parsing_t *p_val)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	j = 0;
	p_val->nsp = 0;
	while (i < p_val->mapH)
	{
		j = 0;
		while (j < (p_val->mapW - 1))
		{
			if (p_val->map[i][j] == '2')
				p_val->nsp++;
			j++;
		}
		i++;
	}
	if (!(p_val->ssp = (sprite_t *)malloc(sizeof(sprite_t) *
			p_val->nsp)))
	{
		printf("Erreur malloc sprite\n");
		exit(EXIT_FAILURE);
	}
	ft_get_location_sp(p_val);
}

int				ft_get_texx(sp_params_t *sp_p, int w)
{
	return (((256 * (sp_p->drawstartx - (-sp_p->sp_w
		/ 2 + sp_p->screenx)) * w / sp_p->sp_w) / 256));
}

int				ft_get_texy(parsing_t *p_val, sp_params_t *sp, int j)
{
	return (((((j) * 256 - p_val->screenH * 128 + sp->sp_h * 128)
		* p_val->sp_texture.h) / sp->sp_h) / 256);
}

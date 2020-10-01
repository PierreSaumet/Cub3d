/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 3 functions:
**  - 'ft_init_structure(parsing_t *p_st)': main loop for initialize the
**  structure.
**  - 'ft_init_mlx(parsing_t *parsing_val)': initializes the mlx pointers
**  - 'ft_check_size_screen(parsing_t *p_val)': checks the size of the
**  screen.
*/

static void				ft_check_size_screen(parsing_t *p_val)
{
	int					w;
	int					h;

	mlx_get_screen_size(p_val->mlx_val.mlx_ptr, &w, &h);
	if (p_val->screenH > h)
		p_val->screenH = h;
	if (p_val->screenW > w)
		p_val->screenW = w;
}

static void				ft_init_mlx(parsing_t *p_val)
{
	if ((p_val->mlx_val.mlx_ptr = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	ft_check_size_screen(p_val);
	if ((p_val->mlx_val.win_ptr = mlx_new_window(p_val->mlx_val.mlx_ptr,
			p_val->screenW, p_val->screenH,
			"Cub3D")) == NULL)
		exit(EXIT_FAILURE);
	if ((p_val->mlx_val.img_ptr = mlx_new_image(p_val->mlx_val.mlx_ptr,
			p_val->screenW, p_val->screenH)) == NULL)
		exit(EXIT_FAILURE);
	if ((p_val->mlx_val.img_data = mlx_get_data_addr(p_val->mlx_val.img_ptr,
			&p_val->mlx_val.bpp, &p_val->mlx_val.size_l,
			&p_val->mlx_val.endian)) == NULL)
		exit(EXIT_FAILURE);
	p_val->mlx_val.img_i_data = (int *)p_val->mlx_val.img_data;
	if ((p_val->mlx_val.img_ptr2 = mlx_new_image(p_val->mlx_val.mlx_ptr,
			p_val->screenW, p_val->screenH)) == NULL)
		exit(EXIT_FAILURE);
	if ((p_val->mlx_val.img_data2 = mlx_get_data_addr(p_val->mlx_val.img_ptr2,
			&p_val->mlx_val.bpp2, &p_val->mlx_val.size_l2,
			&p_val->mlx_val.endian2)) == NULL)
		exit(EXIT_FAILURE);
}

void					ft_init_structure(parsing_t *p_st)
{
	ft_init_dda(&p_st->dda);
	ft_init_mvt(p_st);
	ft_init_mlx(p_st);
}

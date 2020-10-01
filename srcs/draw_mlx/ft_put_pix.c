/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains only one function.
**  - 'ft_my_mlx_pixel_put(parsing_t *p_val, int x, int y, int color)': put the
**  pixel to display in the image 1 or image 2.
*/

void	ft_my_mlx_pixel_put(parsing_t *p_val, int x, int y, int color)
{
	char	*dst;

	if (p_val->refresh == 0)
	{
		dst = p_val->mlx_val.img_data + (y * p_val->mlx_val.size_l + x *
			(p_val->mlx_val.bpp / 8));
		*(int*)dst = color;
	}
	else if (p_val->refresh == 1)
	{
		dst = p_val->mlx_val.img_data2 + (y * p_val->mlx_val.size_l2 + x *
			(p_val->mlx_val.bpp2 / 8));
		*(int*)dst = color;
	}
}

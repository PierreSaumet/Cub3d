/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**              A faire en fonction des fuites memoiresa VALGRIND
*/

void				ft_free_sprite(t_parsing *p_val)
{
	if (p_val->ssp != NULL)
		free(p_val->ssp);
	p_val->ssp = NULL;
}

void				ft_free_mlx_ptr(void *mlx_ptr)
{
	struct s_xvar	*xvar;

	xvar = mlx_ptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}

void				ft_destroy_texture(t_parsing *p_val)
{
	if (p_val->n_texture.img != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->n_texture.id);
	if (p_val->s_texture.img != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->s_texture.id);
	if (p_val->w_texture.img != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->w_texture.id);
	if (p_val->e_texture.img != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->e_texture.id);
	if (p_val->sp_texture.img != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->sp_texture.id);
}

void				ft_free_map_raycasting(t_parsing *p_val)
{
	int				i;

	i = 0;
	while (i < p_val->maph)
	{
		free(p_val->map[i]);
		i++;
	}
	free(p_val->map);
	p_val->map = NULL;
}

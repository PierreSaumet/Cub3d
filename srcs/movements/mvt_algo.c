/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_algo.c                                         :+:      :+:    :+:   */
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
**  - 'ft_event(*p_val)':     Use mlx_hook and mlx_hook_loop to create
**  a loop and and get the instructions from the player.
**  - 'ft_refresh(t_parsing *p_val)':   This function will call 'ft_check_key',
**  then, call ft_raycasting and finally display the first or the second image.
**  - 'ft_check_key(t_parsing *p_val)': It will call the right function for the
**  player's movements.
**  - 'ft_key_press(int keycode, t_parsing *p_val)':    It will quit the
**  program and use a function to save the player's action.
*/

static int			ft_key_press(int keycode, t_parsing *p_val)
{
	if (keycode == K_ESC)
	{
		ft_destroy_texture(p_val);
		if (p_val->mlx_val.img_ptr != NULL)
			mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->mlx_val.img_ptr);
		if (p_val->mlx_val.img_ptr2 != NULL)
			mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->mlx_val.img_ptr2);
		mlx_clear_window(p_val->mlx_val.mlx_ptr, p_val->mlx_val.win_ptr);
		mlx_destroy_window(p_val->mlx_val.mlx_ptr, p_val->mlx_val.win_ptr);
		ft_free_mlx_ptr(p_val->mlx_val.mlx_ptr);
		ft_free_sprite(p_val);
		ft_free_map_raycasting(p_val);
		exit(EXIT_SUCCESS);
	}
	ft_key_push(keycode, p_val);
	return (0);
}

static void			ft_check_key(t_parsing *p_val)
{
	if (p_val->mvt.forward == 1)
		ft_forward(p_val);
	if (p_val->mvt.backward == 1)
		ft_backward(p_val);
	if (p_val->mvt.right == 1)
		ft_right(p_val);
	if (p_val->mvt.left == 1)
		ft_left(p_val);
	if (p_val->mvt.cam_r == 1)
		ft_cam_r(p_val);
	if (p_val->mvt.cam_l == 1)
		ft_cam_l(p_val);
}

static int			ft_refresh(t_parsing *p_val)
{
	ft_check_key(p_val);
	ft_raycasting(*p_val);
	if (p_val->refresh == 0)
	{
		mlx_put_image_to_window(p_val->mlx_val.mlx_ptr,
			p_val->mlx_val.win_ptr, p_val->mlx_val.img_ptr, 0, 0);
		p_val->refresh = 1;
	}
	else if (p_val->refresh == 1)
	{
		mlx_put_image_to_window(p_val->mlx_val.mlx_ptr,
			p_val->mlx_val.win_ptr, p_val->mlx_val.img_ptr2, 0, 0);
		p_val->refresh = 0;
	}
	return (0);
}

static int			ft_close_window(t_parsing *p_val)
{
	ft_destroy_texture(p_val);
	if (p_val->mlx_val.img_ptr != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->mlx_val.img_ptr);
	if (p_val->mlx_val.img_ptr2 != NULL)
		mlx_destroy_image(p_val->mlx_val.mlx_ptr, p_val->mlx_val.img_ptr2);
	mlx_clear_window(p_val->mlx_val.mlx_ptr, p_val->mlx_val.win_ptr);
	mlx_clear_window(p_val->mlx_val.mlx_ptr, p_val->mlx_val.win_ptr);
	mlx_destroy_window(p_val->mlx_val.mlx_ptr, p_val->mlx_val.win_ptr);
	ft_free_sprite(p_val);
	ft_free_map_raycasting(p_val);
	exit(EXIT_SUCCESS);
	return (0);
}

void				ft_event(t_parsing *p_val)
{
	mlx_hook(p_val->mlx_val.win_ptr, 3, 1L << 1, ft_key_release, p_val);
	mlx_hook(p_val->mlx_val.win_ptr, 2, 1L << 0, ft_key_press, p_val);
	mlx_hook(p_val->mlx_val.win_ptr, 17, 1L << 17, ft_close_window, p_val);
	mlx_loop_hook(p_val->mlx_val.mlx_ptr, ft_refresh, p_val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_cam.c                                          :+:      :+:    :+:   */
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
**  -'ft_cam_r(parsing_t *p_val)':      Rotate the camera on the right side,
**  use ROTSPEED (0.01, faster? increase it!).
**  -'ft_cam_l(parsing_t *p_val)':      Rotate the camera on the left side,
**  use ROTSPEED (0.01, faster? increase it!).
**  -'ft_key_release(int keycode, parsing_t *p_val)':   Put the value of the
**  command to 0. (The player stop using this command).
**  -'ft_key_push(int keycode, parsing_t *p_val)':      Put the value of the
**  command to 1. (The player is using this command).
*/

void			ft_cam_r(parsing_t *p_val)
{
	double		olddirx;
	double		oldplanex;

	olddirx = p_val->dirX;
	oldplanex = p_val->planeX;
	p_val->dirX = p_val->dirX * cos(-ROTSPEED) - p_val->dirY * sin(-ROTSPEED);
	p_val->dirY = olddirx * sin(-ROTSPEED) + p_val->dirY * cos(-ROTSPEED);
	p_val->planeX = p_val->planeX * cos(-ROTSPEED) - p_val->planeY
		* sin(-ROTSPEED);
	p_val->planeY = oldplanex * sin(-ROTSPEED) + p_val->planeY * cos(-ROTSPEED);
}

void			ft_cam_l(parsing_t *p_val)
{
	double		olddirx;
	double		oldplanex;

	olddirx = p_val->dirX;
	oldplanex = p_val->planeX;
	p_val->dirX = p_val->dirX * cos(ROTSPEED) - p_val->dirY * sin(ROTSPEED);
	p_val->dirY = olddirx * sin(ROTSPEED) + p_val->dirY * cos(ROTSPEED);
	p_val->planeX = p_val->planeX * cos(ROTSPEED) - p_val->planeY
		* sin(ROTSPEED);
	p_val->planeY = oldplanex * sin(ROTSPEED) + p_val->planeY * cos(ROTSPEED);
}

int				ft_key_release(int keycode, parsing_t *p_val)
{
	if (keycode == K_W)
		p_val->mvt.forward = 0;
	if (keycode == K_S)
		p_val->mvt.backward = 0;
	if (keycode == K_D)
		p_val->mvt.right = 0;
	if (keycode == K_A)
		p_val->mvt.left = 0;
	if (keycode == K_AR_R)
		p_val->mvt.cam_r = 0;
	if (keycode == K_AR_L)
		p_val->mvt.cam_l = 0;
	return (0);
}

int				ft_key_push(int keycode, parsing_t *p_val)
{
	if (keycode == K_W)
		p_val->mvt.forward = 1;
	if (keycode == K_S)
		p_val->mvt.backward = 1;
	if (keycode == K_D)
		p_val->mvt.right = 1;
	if (keycode == K_A)
		p_val->mvt.left = 1;
	if (keycode == K_AR_R)
		p_val->mvt.cam_r = 1;
	if (keycode == K_AR_L)
		p_val->mvt.cam_l = 1;
	return (0);
}

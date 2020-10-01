/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
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
**  - 'ft_forward(t_parsing *p_val)':   Checks if the player can go forward.
**  - 'ft_backward(t_parsing *p_val)':  Checks if the player can go backward.
**  - 'ft_right(t_parsing *p_val)':     Checks if the player can go at
**	his right.
**  - 'ft_left(t_parsing *p_val)':      Checks if the player can go at
**	his left.
*/

void					ft_forward(t_parsing *p_val)
{
	if (p_val->map[(int)(p_val->posx + p_val->dirx * MOVESPEED)]
			[(int)p_val->posy] == '0')
		p_val->posx += p_val->dirx * MOVESPEED;
	if (p_val->map[(int)p_val->posx][(int)(p_val->posy + p_val->diry
			* MOVESPEED)] == '0')
		p_val->posy += p_val->diry * MOVESPEED;
}

void					ft_backward(t_parsing *p_val)
{
	if (p_val->map[(int)(p_val->posx - p_val->dirx * MOVESPEED)]
			[(int)p_val->posy] == '0')
		p_val->posx -= p_val->dirx * MOVESPEED;
	if (p_val->map[(int)(p_val->posx)][(int)(p_val->posy - p_val->diry
			* MOVESPEED)] == '0')
		p_val->posy -= p_val->diry * MOVESPEED;
}

void					ft_right(t_parsing *p_val)
{
	double				ndirx;
	double				ndiry;

	ndirx = p_val->diry;
	ndiry = -p_val->dirx;
	if (p_val->map[(int)(p_val->posx + ndirx * MOVESPEED)][(int)p_val->posy]
			== '0')
		p_val->posx += ndirx * MOVESPEED;
	if (p_val->map[(int)p_val->posx][(int)(p_val->posy + ndiry * MOVESPEED)]
			== '0')
		p_val->posy += ndiry * MOVESPEED;
}

void					ft_left(t_parsing *p_val)
{
	double				ndirx;
	double				ndiry;

	ndirx = -p_val->diry;
	ndiry = p_val->dirx;
	if (p_val->map[(int)(p_val->posx + ndirx * MOVESPEED)][(int)p_val->posy]
			== '0')
		p_val->posx += ndirx * MOVESPEED;
	if (p_val->map[(int)p_val->posx][(int)(p_val->posy + ndiry * MOVESPEED)]
			== '0')
		p_val->posy += ndiry * MOVESPEED;
}

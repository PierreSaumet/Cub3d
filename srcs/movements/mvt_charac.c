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
**  - 'ft_forward(parsing_t *p_val)':   Checks if the player can go forward.
**  - 'ft_backward(parsing_t *p_val)':  Checks if the player can go backward.
**  - 'ft_right(parsing_t *p_val)':     Checks if the player can go at
**	his right.
**  - 'ft_left(parsing_t *p_val)':      Checks if the player can go at
**	his left.
*/

void					ft_forward(parsing_t *p_val)
{
	if (p_val->map[(int)(p_val->posX + p_val->dirX * MOVESPEED)]
			[(int)p_val->posY] == '0')
		p_val->posX += p_val->dirX * MOVESPEED;
	if (p_val->map[(int)p_val->posX][(int)(p_val->posY + p_val->dirY
			* MOVESPEED)] == '0')
		p_val->posY += p_val->dirY * MOVESPEED;
}

void					ft_backward(parsing_t *p_val)
{
	if (p_val->map[(int)(p_val->posX - p_val->dirX * MOVESPEED)]
			[(int)p_val->posY] == '0')
		p_val->posX -= p_val->dirX * MOVESPEED;
	if (p_val->map[(int)(p_val->posX)][(int)(p_val->posY - p_val->dirY
			* MOVESPEED)] == '0')
		p_val->posY -= p_val->dirY * MOVESPEED;
}

void					ft_right(parsing_t *p_val)
{
	double				ndirx;
	double				ndiry;

	ndirx = p_val->dirY;
	ndiry = -p_val->dirX;
	if (p_val->map[(int)(p_val->posX + ndirx * MOVESPEED)][(int)p_val->posY]
			== '0')
		p_val->posX += ndirx * MOVESPEED;
	if (p_val->map[(int)p_val->posX][(int)(p_val->posY + ndiry * MOVESPEED)]
			== '0')
		p_val->posY += ndiry * MOVESPEED;
}

void					ft_left(parsing_t *p_val)
{
	double				ndirx;
	double				ndiry;

	ndirx = -p_val->dirY;
	ndiry = p_val->dirX;
	if (p_val->map[(int)(p_val->posX + ndirx * MOVESPEED)][(int)p_val->posY]
			== '0')
		p_val->posX += ndirx * MOVESPEED;
	if (p_val->map[(int)p_val->posX][(int)(p_val->posY + ndiry * MOVESPEED)]
			== '0')
		p_val->posY += ndiry * MOVESPEED;
}

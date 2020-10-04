/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 1 function used for the raycasting.
**  - 'ft_raycasting(t_parsing pars_val)': main loop for raycasting.
*/

int				ft_raycasting(t_parsing pars_val)
{
	int			x;
	double		*z_buff;

	x = 0;
	if (!(z_buff = (double *)malloc(sizeof(double) * pars_val.screenw)))
	{
		ft_puterror("erreur du malloc de sprite\n");
		exit(EXIT_FAILURE);
	}
	while (x < pars_val.screenw)
	{
		ft_init_raycast(&pars_val, x);
		ft_calc_stepx_y(&pars_val);
		ft_dda(&pars_val);
		ft_calc_perp_draw(&pars_val, &z_buff[x]);
		ft_put_txt_buff(&pars_val, x);
		x++;
	}
	ft_draw_sprite(&pars_val, z_buff);
	free(z_buff);
	return (0);
}

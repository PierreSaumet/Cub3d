/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_parsing_raycasting.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 5 functions:
**  - 'ft_strcpy_map(char *dst, char *src)':    find the NSWE and change it
**  - 'ft_cpy_map(t_data *data, parsing_t *p_val)': copy the map.
**  - 'ft_get_position(t_data *data, parsing_t *p_val)':    get the position
**  - 'ft_rgb(int r, int g, int b)':    return the int used for the color of
**  ceiling or floor.
**  - 'ft_cpy_structure(t_data *data, parsing_t *p_val)': copy the data from
**  the parsing to the structure used for the raycasting.
*/

static char				*ft_strcpy_map(char *dst, char *src)
{
	char				*str;
	int					i;

	str = dst;
	i = 0;
	while (src[i])
	{
		if (src[i] == 'N' || src[i] == 'S' || src[i] == 'E' ||
				src[i] == 'W')
			dst[i] = '0';
		else
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (str);
}

void					ft_cpy_map(t_data *data, parsing_t *p_val)
{
	int					i;

	i = 0;
	if (!(p_val->map = (char **)malloc(sizeof(char *) * (data->map_h + 1))))
	{
		printf("erreur malloc tablea 1\n");
		exit(EXIT_FAILURE);
	}
	while (i < data->map_h + 1)
	{
		if (!(p_val->map[i] = malloc(sizeof(char *) * data->map_w)))
		{
			printf("erreur malloc tableau 2\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < data->map_h + 1)
	{
		ft_strcpy_map(p_val->map[i], data->map[i]);
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

static void				ft_get_position(t_data *data, parsing_t *p_val)
{
	if (data->charac == 'N')
	{
		p_val->dirX = -1;
		p_val->dirY = 0;
	}
	else if (data->charac == 'S')
	{
		p_val->dirX = 1;
		p_val->dirY = 0;
	}
	else if (data->charac == 'W')
	{
		p_val->dirX = 0;
		p_val->dirY = -1;
	}
	else if (data->charac == 'E')
	{
		p_val->dirX = 0;
		p_val->dirY = 1;
	}
	else
		quit("The character should be only NSW or E\n");
}

static int				ft_rgb(int r, int g, int b)
{
	return ((256 * 256 * r) + (256 * g) + b);
}

void					ft_cpy_structure(t_data *data, parsing_t *p_val)
{
	double				radian;

	radian = (60 / 2) * (3.14159275 / 180);
	ft_init_parsing(p_val);
	p_val->screenW = data->rx;
	p_val->screenH = data->ry;
	p_val->mapH = data->map_h + 1;
	p_val->mapW = data->map_w + 1;
	p_val->posX = (double)data->c_y + 0.5;
	p_val->posY = (double)data->c_x + 0.5;
	ft_get_position(data, p_val);
	p_val->planeX = (p_val->dirY * tan(radian / 2.0));
	p_val->planeY = -(p_val->dirX * tan(radian / 2.0));
	p_val->refresh = 0;
	p_val->floor = ft_rgb(data->fr, data->fg, data->fb);
	p_val->ceiling = ft_rgb(data->cr, data->cg, data->cb);
	p_val->nsp = 0;
}

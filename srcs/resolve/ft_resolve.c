/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
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
**  - 'ft_resolve(t_map *map, t_data *data)':   call the different functions.
**  - 'ft_malloc_tab(t_map *map, t_data *data)':    allocate the right size
**  for the map.
**  - 'cpy_tab(t_map *map, t_data *data)':  copy the first map into the second.
**  - 'ft_find_carac(t_map *map, t_data *data)': find the position of the
**  character.
*/

void			cpy_tab(t_map *map, t_data *data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < data->map_h + 1)
	{
		j = 0;
		while (j <= data->map_w)
		{
			map->map2[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
}

static void		ft_malloc_tab(t_map *map, t_data *data)
{
	int			i;

	i = 0;
	if (!(map->map2 = (char **)malloc(sizeof(char *) * (data->map_h + 1))))
		ft_error_map(data, "Can not malloc the second map!\n");
	while (i < data->map_h + 1)
	{
		if (!(map->map2[i] = malloc(sizeof(char *) * data->map_w)))
			ft_error_map(data, "Can not malloc the second map!\n");
		i++;
	}
}

static void		ft_find_carac(t_map *map, t_data *data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < data->map_h + 1)
	{
		j = 0;
		while (j < data->map_w + 1)
		{
			if (map->map2[i][j] == 'S' || map->map2[i][j] == 'N'
					|| map->map2[i][j] == 'E' || map->map2[i][j] == 'W')
			{
				map->x_c = j;
				map->y_c = i;
			}
			j++;
		}
		i++;
	}
}

void			ft_resolve(t_map *map, t_data *data)
{
	int			ret;

	ret = 0;
	ft_malloc_tab(map, data);
	cpy_tab(map, data);
	ft_find_carac(map, data);
	ret = find_object(map, data);
	if (ret == 1)
	{
		ft_free_map(map, data);
		ft_error_map(data, "le personnage peut sortir\n");
	}
}

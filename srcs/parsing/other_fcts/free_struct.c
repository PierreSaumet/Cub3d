/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
**  This file contains 4 functions:
**	- 'ft_error_map(t_data *data, char *str)':	free ptr, struc, display error
**	and exit.
**	- 'ft_free_map(t_map *map, t_data *data)':	free the map.
**  - 'ft_free_struct(t_data *data)':   free all the datas from the structure
**  called 's_data'.
**  - 'ft_free_map(t_map *map, t_data *data)':  free the map from the structure
**  called 's_map'.
*/

void			ft_error_map(t_data *data, char *str)
{
	ft_free_ptr(data);
	ft_free_struct(data);
	ft_puterror(str);
	exit(EXIT_FAILURE);
}

void			ft_free_map(t_map *map, t_data *data)
{
	int			i;

	i = 0;
	while (i < data->map_h + 1)
	{
		free(map->map2[i]);
		i++;
	}
	free(map->map2);
	map->map2 = NULL;
}

void			ft_free_struct(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->map_h + 1)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	free(data->pt_no);
	free(data->pt_so);
	free(data->pt_we);
	free(data->pt_ea);
	free(data->pt_sp);
}

void			ft_free_ptr(t_data *data)
{
	free(data->pt_no);
	data->pt_no = NULL;
	free(data->pt_so);
	data->pt_so = NULL;
	free(data->pt_ea);
	data->pt_ea = NULL;
	free(data->pt_we);
	data->pt_we = NULL;
	free(data->pt_sp);
	data->pt_sp = NULL;
}

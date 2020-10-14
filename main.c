/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/headers/cub3d.h"

/*
**  This file contains 5 functions:
**  - 'main(int argc, char **argv)':    the main function, checks arguments
**  and process the program.
**  - 'ft_bmp(char **argv, t_data *data, t_parsing *parsing_val, t_map *map)':
**  init the parameters for saving the bmp file.
**  - 'ft_init_game(t_data *data, t_parsing *parsing_val)': copy the structure
**  from parsing to raycasting and init the other paranms for the raycasting.
**  - 'ft_start_game(t_parsing parsing_val)':   main loop for the raycasting and
**  uses the minilibx.
**  - 'ft_start_parsing(char **argv, t_data *data, t_map *map)':    starts
**  the parsing form the .cub.
*/

void			ft_start_parsing(char **argv, t_data *data, t_map *map)
{
	int			i;

	i = 0;
	init_map(map);
	init_params(data);
	check_arg(argv[1]);
	parsing_param(argv[1], data);
	get_map(argv[1], data);
	check_index_map(data);
	change_sp_map(data);
	ft_check_map(data);
	ft_resolve(map, data);
	while (i < data->map_h + 1)
	{
		free(map->map2[i]);
		i++;
	}
	free(map->map2);
	map->map2 = NULL;
}

void			ft_start_game(t_parsing parsing_val)
{
	ft_raycasting(parsing_val);
	mlx_put_image_to_window(parsing_val.mlx_val.mlx_ptr,
		parsing_val.mlx_val.win_ptr, parsing_val.mlx_val.img_ptr, 0, 0);
	ft_event(&parsing_val);
	mlx_loop(parsing_val.mlx_val.mlx_ptr);
}

void			ft_init_game(t_data *data, t_parsing *parsing_val, int i)
{
	ft_cpy_structure(data, parsing_val);
	ft_init_structure(parsing_val, i);
	ft_init_texture(parsing_val, data);
	ft_cpy_map(data, parsing_val);
	ft_init_sprite(parsing_val);
}

void			ft_bmp(char **argv, t_data *data,
		t_parsing *parsing_val, t_map *map)
{
	int			fd;

	fd = 0;
	ft_start_parsing(argv, data, map);
	ft_init_game(data, parsing_val, 1);
	ft_raycasting(*parsing_val);
	if (!(fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)))
		ft_error_map(data, "Cannot open the bmp file\n");
	ft_write_bmp(parsing_val, fd);
}

int				main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_parsing	p_val;

	if (argc < 2 || argc > 3)
		ft_puterror2("Need one argument or two with --save!\n");
	else if (argc == 2)
	{
		if (ft_check_empty(argv) == 0)
		{
			ft_start_parsing(argv, &data, &map);
			ft_init_game(&data, &p_val, 0);
			ft_start_game(p_val);
		}
	}
	else if (argc == 3)
		return (ft_bmp_start(argv, &data, &p_val, &map));
	return (0);
}

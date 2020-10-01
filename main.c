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
	i = 0;
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

void			ft_init_game(t_data *data, t_parsing *parsing_val)
{
	ft_cpy_structure(data, parsing_val);
	ft_init_structure(parsing_val);
	ft_init_texture(parsing_val, data);
	ft_cpy_map(data, parsing_val);
	ft_init_sprite(parsing_val);
}

static void		ft_bmp(char **argv, t_data *data,
		t_parsing *parsing_val, t_map *map)
{
	int			fd;

	if (!(fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)))
	{
		printf("Cannot open the bmp file\n");
		exit(EXIT_FAILURE);
	}
	ft_start_parsing(argv, data, map);
	ft_init_game(data, parsing_val);
	ft_raycasting(*parsing_val);
	ft_write_bmp(parsing_val, fd);
}

int				main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_parsing	p_val;
	t_dda		dda_val;

	if (argc < 2 || argc > 3)
		quit("Need one argument or two with --save!\n");
	else if (argc == 2)
	{
		ft_start_parsing(argv, &data, &map);
		ft_init_game(&data, &p_val);
		ft_start_game(p_val);
	}
	else if (argc == 3)
	{
		if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
				&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
			ft_bmp(argv, &data, &p_val, &map);
		ft_destroy_texture(&p_val);
		ft_bmp_exit(p_val);
		ft_free_sprite(&p_val);
		ft_free_map_raycasting(&p_val);
	}
	return (0);
}

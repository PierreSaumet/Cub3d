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
**  - 'ft_bmp(char **argv, t_data *data, parsing_t *parsing_val, t_map *map)':
**  init the parameters for saving the bmp file.
**  - 'ft_init_game(t_data *data, parsing_t *parsing_val)': copy the structure
**  from parsing to raycasting and init the other paranms for the raycasting.
**  - 'ft_start_game(parsing_t parsing_val)':   main loop for the raycasting and
**  uses the minilibx.
**  - 'ft_start_parsing(char **argv, t_data *data, t_map *map)':    starts
**  the parsing form the .cub.
*/

void            ft_start_parsing(char **argv, t_data *data, t_map *map)
{
    int         i;

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

void            ft_start_game(parsing_t parsing_val)
{
    ft_raycasting(parsing_val);
    mlx_put_image_to_window(parsing_val.mlx_val.mlx_ptr,
        parsing_val.mlx_val.win_ptr, parsing_val.mlx_val.img_ptr, 0, 0);
    ft_event(&parsing_val);
    mlx_loop(parsing_val.mlx_val.mlx_ptr);
}

void            ft_init_game(t_data *data, parsing_t *parsing_val)
{
    ft_cpy_structure(data, parsing_val);
    ft_init_structure(parsing_val);
    ft_init_texture(parsing_val, data);
    ft_cpy_map(data, parsing_val);
    ft_init_sprite(parsing_val);
}

static void            ft_bmp(char **argv, t_data *data,
        parsing_t *parsing_val, t_map *map)
{
    int         fd;

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

/*****************************************************
** fonctins pour les free   **************************
*****************************************************
*/
void            ft_full_free1(t_data data, t_map map)
{
    // Libere les pointeurs pt_no et so and co
    free(data.pt_no);
    data.pt_no = NULL;
    free(data.pt_so);
    data.pt_so = NULL;
    free(data.pt_ea);
    data.pt_ea = NULL;
    free(data.pt_we);
    data.pt_we = NULL;
    free(data.pt_sp);
    data.pt_sp = NULL;
    
    // Libere data->map (premiere map pour recuperer les donnees)
    int         i;
    i = 0;
    while (i < data.map_h + 1)
    {
        free(data.map[i]);
        i++;
    }
    free(data.map);
    data.map = NULL;

    // Libere data->map2 (deuxieme map pour le  resorlve)
    i = 0;
    while (i < data.map_h + 1)
    {
        free(map.map2[i]);
        i++;
    }
    free(map.map2);
    map.map2 = NULL;

}

void            ft_full_free_2(t_data data, parsing_t p_val, t_map map)
{
    // Libere la 3eme map utilisee pour le raycasting
    int         i;
    i = 0;
    //printf("p_val.maph = %d p_val.mapW =%d\n", p_val.mapH, p_val.mapW);
    while (i < data.map_h + 1)
    {
        free(p_val.map[i]);
        i++;                                        // A CORRIGER
    }
    free(p_val.map);
    p_val.map = NULL;

    // Libere les sprites de ssp
    free(p_val.ssp);
    p_val.ssp = NULL;


}


//reste dans ce fichier
int             main(int argc, char **argv)
{
    t_data      data;
    t_map       map;
    parsing_t   parsing_val;
    dda_t       dda_val;

    if (argc < 2 || argc > 3)
        quit("Need one argument or two with --save!\n");
    
    else if (argc == 2)
    {
        
        ft_start_parsing(argv, &data, &map);
        //ft_full_free1(data, map);
        ft_init_game(&data, &parsing_val);
        
        //ft_full_free1(data, map);
        //ft_full_free_2(data, parsing_val, map);
        //printf("p_val.maph = %d p_val.mapW =%d et data.map_h + 1 = %d\n", parsing_val.mapH, parsing_val.mapW, data.map_h + 1);
        ft_start_game(parsing_val);
        
        //printf("bonjour?\n");
    }
    /*
    else if (argc == 3)
    {
        if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
                && argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
            ft_bmp(argv, &data, &parsing_val, &map);
    }
    */
    return (0);
}

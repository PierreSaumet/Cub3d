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

#include "srcs/headers/cube3d.h"

/*
**  This file contains 1 file:
**  - 'main(int argc, char **argv)':    launches the main functions
*/


int         main(int argc, char **argv)
{
    t_data  data;
    t_map   map;

    init_map(&map);
    init_params(&data);
    if (argc != 2)
        quit("Need one argument !\n");
    else
    {
        check_arg(argv[1]);
        parsing_param(argv[1], &data);
    }
    // Affiche les parametres
    ft_display_params(&data);

    // Recupere la carte
    get_map(argv[1], &data);

    // Affiche la carte
    ft_display_map(&data); 

    // Verifie la carte
    check_index_map(&data);

    // Change les espaces en 1
    change_sp_map(&data);

    // Affiche la carte
    ft_display_map(&data); 

    // Fait le parsing
    ft_check_map(&data);

    //  Affiche la carte
    ft_display_map(&data); 



    // RESOLVE PB AVEC OBJECT
    ft_resolve(&map, &data);


    // Libere les mallocs
    ft_free_map(&map, &data);
    ft_free_struct(&data);
    return (0);
}
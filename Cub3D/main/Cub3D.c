/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:53:37 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:43:44 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/cub3D.h"
#include "../headers/libft.h"


int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("ERROR need 1 argument with the extension '.cub'\n");
		return (-1);
	}
	else
	{
		if (ft_check_arg(argv[1]) == 0)
			ft_parsing(argv[1]);
		else
			return (-1);
	}
	return (0);
}

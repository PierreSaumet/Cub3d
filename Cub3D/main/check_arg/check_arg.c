/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:34:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:51:43 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"
#include "../../headers/get_next_line.h"
#include "../../headers/libft.h"

/*
** This function will check if the argument passed
** finished with '.cub.
** if it is true, returns 0.
** if not, display an error message et return 1
*/

int			ft_check_arg(char *argv)
{
	int		i;

	i = 0;
	while(argv[i])
	{
		if (argv[i] == '.')
		{
			if (argv[i + 1] == 'c' && argv[i + 2] == 'u'
					&& argv[i + 3] == 'b' && argv[i + 4] == '\0')
				return (0);
		}
		i++;
	}
	ft_putstr("ERROR, only one argument with the extension '.cub'\n");
	return (1);
}
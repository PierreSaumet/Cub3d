/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
**	This file contains 2 functions:
**  - 'change_sp_map(t_data *data)':    browse the buffer and call change_sp.
**  - 'change_sp(t_data *data, int i, int j)':  change the space character
**  into a '1' etc.
*/

int					change_sp(t_data *data, int i, int j)
{
	printf("data->map[i][j] == %c\n", data->map[i][j]);
	if (data->map[i][j] == ' ')
		data->map[i][j] = '1';
	else if (data->map[i][j] == '\n')
		data->map[i][j] = '1';
	else if (data->map[i][j] == '\0')
	{
		printf("la\n");
		
		data->map[i][j] = '9';
		while (j < data->map_w)
		{
			data->map[i][j] = '9';
			j++;
		}
		data->map[i][data->map_w] = '\0';
		return (j);
	}
	else if (data->map[i][j] == '\t')
		data->map[i][j] = '1';
	return (j);
}

int				ft_nines(t_data *d)
{
	int				i;
	int				j;

	i = d->map_h;
	j = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < d->map_w)
		{
			//printf("i+1=%d et h=%d\n", i+1, d->map_h);
			if (d->map[i][j] == '0'
					&& (i + 1 < d->map_h)
					&& d->map[i + 1][j] == '9')
			{
				return (ft_puterror2("Map not close\n"));
			}
			j++;
		}
		i--;
	}
	return (0);
}

int				ft_nine(t_data *d)
{
	int				i;
	int				j;

	i = 1;
	j = 0;
	while (i < d->map_h + 1)
	{
		j = 0;
		while (j < d->map_w)
		{
			if (d->map[i][j] == '0'
					&& d->map[i - 1][j] == '9')
			{
				return (ft_puterror2("Map not close\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			test(t_data *d)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < d->map_h + 1)
	{
		j = 0;
		while (j < d->map_w)
		{
			if (d->map[i][j] == '9')
				d->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void				change_sp_map(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i <= data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			j = change_sp(data, i, j);
			if (j == data->map_w)
				data->map[i][j] = '\0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->map_h + 1)
	{
		printf("MAP=%d\t-%s-\n", i, data->map[i]);
		i++;
	}
	int ret;
	ret = ft_nine(data);
	if (ret == 1)
		exit(EXIT_FAILURE);
	else
	{
		printf("MHHHHH ici?\n");
		ret = ft_nines(data);
		printf("MHHHHH la?\n");
		if (ret == 1)
		{
			printf("lerde\n");
		}
		else
			printf("OK\n");
		test(data);
		//exit(EXIT_FAILURE);
	}
}

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
**	This file contains 5 functions:
**  - 'change_sp_map(t_data *data)':    browse the buffer and call change_sp.
**  - 'change_sp(t_data *data, int i, int j)':  change the space character
**  into a '9' etc.
**	- 'ft_nines(t_data *d)':	checks if there is a 0 and after him a 9, if
**	yes return 1 == ERROR.
**	- 'ft_nine(t_data *d)':		checks if there is a 0 and before him a 9, if
**	yes return 1 == ERROR.
**	- 'ft_replace(t_data *d)':	replace 9 by 1 if everything is okay.
*/

static int			change_sp(t_data *data, int i, int j)
{
	if (data->map[i][j] == ' ')
		data->map[i][j] = '1';
	else if (data->map[i][j] == '\n')
		data->map[i][j] = '1';
	else if (data->map[i][j] == '\0')
	{
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

int					ft_nines(t_data *d)
{
	int				i;
	int				j;
	char			*x;

	i = d->map_h;
	j = 0;
	x = "NSWE";
	while (i >= 0)
	{
		j = 0;
		while (j < d->map_w)
		{
			if (d->map[i][j] == '0'
					&& (i + 1 <= d->map_h)
					&& d->map[i + 1][j] == '9')
				return (ft_puterror2("Map not close\n"));
			if ((d->map[i][j] == x[0] || d->map[i][j] == x[1]
					|| d->map[i][j] == x[2] || d->map[i][j] == x[3])
					&& (i + 1 <= d->map_h) && d->map[i + 1][j] == '9')
				return (ft_puterror2("Charac is on border\n"));
			j++;
		}
		i--;
	}
	return (0);
}

int					ft_nine(t_data *d)
{
	int				i;
	int				j;
	char			*x;

	i = 1;
	j = 0;
	x = "NSWE";
	while (i < d->map_h + 1)
	{
		j = 0;
		while (j < d->map_w)
		{
			if (d->map[i][j] == '0'
					&& d->map[i - 1][j] == '9')
				return (ft_puterror2("Map not close\n"));
			if ((d->map[i][j] == x[0] || d->map[i][j] == x[1]
					|| d->map[i][j] == x[2] || d->map[i][j] == x[3])
					&& d->map[i - 1][j] == '9')
				return (ft_puterror2("Charac is on border\n"));
			j++;
		}
		i++;
	}
	return (0);
}

static void			ft_replace(t_data *d)
{
	int				i;
	int				j;

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
	int				ret;

	i = 0;
	j = 0;
	ret = 0;
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
	ret = ft_end(data);
	if (ret == 1)
		ft_exit(data);
	ft_replace(data);
}

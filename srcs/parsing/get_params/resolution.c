/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
**	This file contains 2 functions:
**  - 'get_r(t_data *data, char *line)':    call check_r_line and get the
**  number with ft_atoi().
**  - 'check_r_line(t_data *data, char *line)': check if the line is only
**  composed with letters.
*/

static int			check_r_line(t_data *data, char *line)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (data->rx != 0 && data->ry != 0)
		ft_error_map(data, "Resolution has already been assigned!\n");
	while (line[i])
	{
		if (ft_isspace((int)line[i]) == 1
				|| (line[i] >= '0' && line[i] <= '9'))
		{
			if ((line[i] >= '0' && line[i] <= '9') && line[i - 1] == ' ')
				j++;
			i++;
		}
		else
			return (ft_puterror2("Reso: There should be only number...\n"));
	}
	if (j > 2)
		return (ft_puterror2("Reso : There sould be only 2 numbers! \n"));
	return (0);
}

int					ft_final_check_r(t_data *data)
{
	if (data->rx > 2147483647)
		data->rx = 2147483647;
	if (data->rx < 0)
		data->rx = 2147483647;
	if (data->ry > 2147483647)
		data->ry = 2147483647;
	if (data->ry < 0)
		data->ry = 2147483647;
	if (data->rx < 0 || data->ry < 0)
	{
		ft_puterror("Resolution should be positive!\n");
		return (1);
	}
	else if (data->rx == 0 || data->ry == 0)
	{
		ft_puterror("Resolution should not be equal to 0!\n");
		return (1);
	}
	return (0);
}

int					get_r(t_data *data, char *line)
{
	int				i;
	int				ret;

	i = 0;
	if (data->rx != 0 || data->ry != 0)
	{
		ft_puterror("Resolution already assigned\n");
		return (1);
	}
	ret = check_r_line(data, line);
	data->rx = ft_atoi(line);
	while (ft_isspace((int)line[i]) == 1)
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	data->ry = ft_atoi(&line[i]);
	if (ret == 0)
		ret = ft_final_check_r(data);
	return (ret);
}

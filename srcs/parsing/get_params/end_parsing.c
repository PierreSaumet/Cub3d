/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
**	This file contains 5 functions:
**	- ft_exit(t_data *data):	free everything if the map is not correct.
**	- ft_get_data_end(void):	print an error message.
**	- 'ft_end_parsing(t_data *data, char *line, int ret)': final check of
**	the map.
**	- 'ft_ret_gnl_pars_param(int fd, int ret, t_data *data)':	get
**	the datas
**	- 'ft_final_check_c_f(t_data *d, int ret)': check the ceiling and floor.
*/

void				ft_exit(t_data *data)
{
	int				i;

	i = 0;
	while (i < data->map_h + 1)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->pt_no);
	free(data->pt_so);
	free(data->pt_ea);
	free(data->pt_we);
	free(data->pt_sp);
	exit(EXIT_FAILURE);
}

int					ft_get_data_end(void)
{
	ft_puterror("There is something wrong with the datas... \n");
	return (1);
}

static int			ft_end_parsing(t_data *data, char *line, int ret)
{
	data->tt_line++;
	if (!(line[0]))
		data->tt_empty++;
	data->map_w = (data->map_w < ft_strlen(line)
			? ft_strlen(line) : data->map_w);
	if (ret == 0)
		if (check_line(data, line) == 1)
			ret = 1;
	return (ret);
}

int					ft_ret_gnl_pars_param(int fd, int ret,
		t_data *data)
{
	char			*line;

	while (get_next_line(fd, &line))
	{
		if (ret == 0)
		{
			if (!line)
				return (2);
			data->tt_line++;
			if (data->nb_data < 8)
			{
				if (check_line(data, line) == 1)
					ret = 1;
				free(line);
			}
			else
				count_map(data, line);
		}
		else
			free(line);
	}
	ret = ft_end_parsing(data, line, ret);
	free(line);
	data->map_h = data->map_h - data->tt_empty;
	return (ret);
}

int					ft_final_check_c_f(t_data *d, int ret, int i)
{
	if (i == 1 && ret == 0)
	{
		if (d->fr < 0 || d->fr > 255)
			return (ft_puterror2("1) RGB floor is wrong. 0 / 255\n"));
		if (d->fg < 0 || d->fg > 255)
			return (ft_puterror2("2) RGB floor is wrong. 0 / 255\n"));
		if (d->fb < 0 || d->fb > 255)
			return (ft_puterror2("3) RGB floor is wrong. 0 / 255\n"));
		return (0);
	}
	if (i == 2 && ret == 0)
	{
		if (d->cr < 0 || d->cr > 255)
			return (ft_puterror2("1) RGB ceiling is wrong. 0 / 255\n"));
		if (d->cg < 0 || d->cg > 255)
			return (ft_puterror2("2) RGB ceiling is wrong. 0 / 255\n"));
		if (d->cb < 0 || d->cb > 255)
			return (ft_puterror2("3) RGB ceiling is wrong. 0 / 255\n"));
		return (0);
	}
	return (ret);
}

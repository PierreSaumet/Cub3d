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

int					ft_final_check_c_f(t_data *d, int ret)
{
	if (ret == 0)
	{
		if ((d->cr < 0 || d->cr > 255) && (d->fr < 0 || d->fr > 255))
		{
			ft_puterror("1) RGB ceiling or floor is wrong. 0 / 255\n");
			return (1);
		}
		if ((d->cb < 0 || d->cb > 255) && (d->fb < 0 || d->fb > 255))
		{
			ft_puterror("2) RGB ceiling or floor is wrong. 0 / 255\n");
			return (1);
		}
		if ((d->cg < 0 || d->cg > 255) && (d->fg < 0 || d->fg > 255))
		{
			ft_puterror("3) RGB ceiling or floor is wrong. 0 / 255\n");
			return (1);
		}
		return (0);
	}
	else
		return (ret);
}

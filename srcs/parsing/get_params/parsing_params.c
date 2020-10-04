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
**  This file contains 5 functions:
**  - 'parsing_param(char *argv, t_data *data)':    open GNL, get the data
**  and count the map's lines.
**  - 'count_map(t_data *data, char *line)':    count the map's line.
**  - 'check_line(t_data *data, char *line)':   check if the line contains
**  a letter then call check_letter.
**  - 'check_letter(char c)':   check if the letter is correct.
**  - 'get_data(t_data *data, char *line)':     call the function corresponding
**  to the letter.
*/

static int			get_data(t_data *data, char *line)
{
	int				ret;

	ret = 0;
	data->nb_data++;
	if (line[0] == 'R' && line[1] == ' ')
		ret = get_r(data, &line[2]);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		ret = get_str(data, &line[3], line[0], data->pt_no);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		ret = get_str(data, &line[3], line[1], data->pt_so);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		ret = get_str(data, &line[3], line[0], data->pt_we);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		ret = get_str(data, &line[3], line[0], data->pt_ea);
	else if (line[0] == 'S' && line[1] == ' ')
		ret = get_str(data, &line[2], line[0], data->pt_sp);
	else if (line[0] == 'F' && line[1] == ' ')
		ret = get_floor(data, &line[2]);
	else if (line[0] == 'C' && line[1] == ' ')
		ret = get_ceilling(data, &line[2]);
	else
		ret = ft_get_data_end();
	return (ret);
}

static int			check_letter(char c, t_data *data)
{
	if (c == 'R' || c == 'N' || c == 'W' || c == 'E' || c == 'S'
			|| c == 'F' || c == 'C')
		return (0);
	else if (c == '\n' || c == '\t' || c == '\0')
		return (0);
	else
	{
		if (data->nb_data < 8)
		{
			ft_puterror("The cub file contains one or many errors!\n");
			return (1);
		}
		else
			return (0);
	}
}

int					check_line(t_data *data, char *line)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	if (data->nb_data < 8)
	{
		while (line[i] == ' ')
			i++;
		ret = check_letter(line[i], data);
		if (line[i] && ret == 0)
		{
			ret = get_data(data, &line[i]);
			data->param_h++;
		}
		else
			data->param_h++;
	}
	return (ret);
}

void				count_map(t_data *data, char *line)
{
	data->map_w = (data->map_w < ft_strlen(line)
		? ft_strlen(line) : data->map_w);
	data->map_h++;
	if (!(line[0]))
		data->tt_empty++;
	free(line);
}

void				parsing_param(char *argv, t_data *data)
{
	int				fd;
	char			*line;
	int				ret;

	fd = open(argv, O_RDONLY);
	ret = 0;
	if (fd >= 3)
		ret = ft_ret_gnl_pars_param(fd, 0, argv, data);
	else
	{
		ret = 1;
		ft_puterror("The map.cub doesn't exist!\n");
	}
	close(fd);
	if (ret == 1)
	{
		ft_free_ptr(data);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
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
**  - 'get_floor(t_data *data, char *line)':    call check_f_or_c() to verify
**  the line, and call get_digit_f() to get the datas.
**  - 'get_digit_f(t_data *data, char *line, int i, int ind)':  get the datas
**  using ft_atoi and return the index of the line.
**  - 'get_ceilling(t_data *data, char *line)': call check_f_or_c() to verify
**  the line, and call get_digit_c() to get the datas
**  - 'get_digit_c(t_data *data, char *line, int i, int ind)':  get the datas
**  using ft_atoi and return the index of the line.
**  - 'check_f_or_c(t_data *data, char *line)':     check if the line contains
**  only number, space and ','.
*/

static int		check_f_or_c(char *l, int ret)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	k = 0;
	while (l[++i])
	{
		if (ft_isspace((int)l[i]) || ft_isdigit((int)l[i])
				|| l[i] == ',')
		{
			if (ft_isdigit((int)l[i]) && (l[i - 1] == ' ' || l[i - 1] == ','))
				j++;
			if (l[i] == ',')
				k++;
			if (j < k || (j == k + 2))
				return (ft_puterror2("',' and numbers are display wrong \n"));
		}
		else
			return (ft_puterror2("Floor Ceiling: numbers and ','! \n"));
	}
	if (j != 3 || k != 2)
		return (ft_puterror2("Floor or Ceiling, 3 numbers and 2 ','. \n"));
	return (ret);
}

static int		get_digit_c(t_data *data, char *line, int i, int ind)
{
	if (ind == 1)
	{
		data->cr = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	else if (ind == 2)
	{
		data->cg = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	else if (ind == 3)
	{
		data->cb = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	return (i);
}

int				get_ceilling(t_data *data, char *line)
{
	int			i;
	int			ret;

	i = 0;
	ret = check_f_or_c(line, 0);
	if (data->cr != -1 && data->cb != -1 && data->cg != -1)
		ret = ft_puterror2("Ceiling already assigned\n");
	while (line[i] && line && ret == 0)
	{
		if (line[i] == ' ' || line[i] == ',')
			i++;
		else if (ft_isdigit((int)line[i]))
		{
			if (data->cr == -1)
				i = get_digit_c(data, line, i, 1);
			else if (data->cg == -1)
				i = get_digit_c(data, line, i, 2);
			else
				i = get_digit_c(data, line, i, 3);
		}
		else
			i++;
	}
	return (ft_final_check_c_f(data, ret));
}

static int		get_digit_f(t_data *data, char *line, int i, int ind)
{
	if (ind == 1)
	{
		data->fr = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	else if (ind == 2)
	{
		data->fg = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	else if (ind == 3)
	{
		data->fb = ft_atoi(&line[i]);
		while (ft_isdigit((int)line[i]))
			i++;
		return (i);
	}
	return (i);
}

int				get_floor(t_data *data, char *line)
{
	int			i;
	int			ret;

	i = 0;
	ret = check_f_or_c(line, 0);
	if (data->fr != -1 && data->fb != -1 && data->fg != -1)
		ret = ft_puterror2("Floor already assigned\n");
	while (line[i] && line && ret == 0)
	{
		if (line[i] == ' ' || line[i] == ',')
			i++;
		else if (ft_isdigit((int)line[i]))
		{
			if (data->fr == -1)
				i = get_digit_f(data, line, i, 1);
			else if (data->fg == -1)
				i = get_digit_f(data, line, i, 2);
			else
				i = get_digit_f(data, line, i, 3);
		}
		else
			i++;
	}
	return (ft_final_check_c_f(data, ret));
}

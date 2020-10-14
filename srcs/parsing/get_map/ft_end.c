/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int			ft_ret(t_data *data, int i)
{
	int				k;
	int				p;

	k = -1;
	p = 0;
	while (++k < data->map_w)
	{
		if (data->map[i][k] == '1')
			p++;
	}
	if (p < 2)
		return (ft_puterror2("Map not close\n"));
	return (0);
}

int					ft_end(t_data *data)
{
	int				i;
	int				j;
	int				ret;

	i = -1;
	j = -1;
	while (++i < data->map_h + 1)
	{
		j = -1;
		while (++j < data->map_w)
		{
			if (data->map[i][j] == '0')
			{
				ret = ft_ret(data, i);
				if (ret == 1)
					return (1);
			}
		}
	}
	if (ret == 0)
		ret = ft_nine(data);
	if (ret == 0)
		ret = ft_nines(data);
	return (ret);
}

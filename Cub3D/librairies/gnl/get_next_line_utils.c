/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:25:39 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:03:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"
#include "../../headers/libft.h"

int		ft_final_check(char **s, char **line, int ret, int fd)
{
	int		i;

	i = 0;
	if (ret < 0)
		i = -1;
	else if (ret == 0 && s[fd] == NULL)
	{
		i = 0;
		ft_free_gnl(line);
		*line = ft_strdup("");
	}
	else
	{
		i = ft_gnl(&s[fd], line);
		if (ret == 0 && s[fd] == NULL)
			i = 0;
	}
	return (i);
}

int		ft_check_ret(char **line, int ret)
{
	if (ret == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

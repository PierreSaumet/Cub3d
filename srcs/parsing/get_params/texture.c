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
**	This file contains  functions:
**  - 'get_str(t_data *data, char *line, char c, char *pt)':    call the right
**  function according to the letter.
**  - 'ft_copy(char *dest, char *src)':     copy the datas into the pointers.
**  - 'ft_malloc(t_data *data, char c, char *line)':    allocate the memory
**  for the pointers from the structure called 's_data'.
**  - 'check_str(char *line)':              check the string et quit the
**  program if it find an error.
*/

static int			check_str(char *line)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (ft_isspace((int)line[i]) == 1 || ft_isalnum((int)line[i]) == 1
			|| line[i] == '/' || line[i] == '-'
			|| line[i] == '_' || line[i] == '.')
		{
			if ((ft_isalnum((int)line[i]) == 1
					|| line[i] == '/' || line[i] == '-' || line[i] == '_'
					|| line[i] == '.') && line[i - 1] == ' ')
				j++;
			i++;
		}
		else
			return (ft_puterror2("Texture's adress not valide!\n"));
	}
	if (j > 1)
		return (ft_puterror2("Texture should have one adress!\n"));
	return (0);
}

static void			ft_malloc(t_data *data, char c, char *line)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (line[i++])
	{
		if (line[i] == ' ')
			j++;
	}
	if (c == 'N')
		if (!(data->pt_no = malloc(ft_strlen(line) - j + 1)))
			ft_error_map(data, "North texture's malloc failed. \n");
	if (c == 'O')
		if (!(data->pt_so = malloc(ft_strlen(line) - j + 1)))
			ft_error_map(data, "South texture's malloc failed. \n");
	if (c == 'W')
		if (!(data->pt_we = malloc(ft_strlen(line) - j + 1)))
			ft_error_map(data, "West texture's malloc failed. \n");
	if (c == 'E')
		if (!(data->pt_ea = malloc(ft_strlen(line) - j + 1)))
			ft_error_map(data, "East texture's malloc failed. \n");
	if (c == 'S')
		if (!(data->pt_sp = malloc(ft_strlen(line) - j + 1)))
			ft_error_map(data, "Sprite texture's malloc failed. \n");
}

static int			ft_copy(char *dest, char *src)
{
	int				i;
	int				fd;

	i = 0;
	fd = 0;
	while (src[i] && ft_isspace((int)src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	fd = open(dest, O_RDONLY);
	if (fd < 3)
	{
		close(fd);
		ft_puterror("erreur ne peut pas ouvrir la texture\n");
		return (1);
	}
	return (0);
}

int					get_str(t_data *data, char *line, char c, char *pt)
{
	int				i;
	int				ret;

	i = 0;
	ret = check_str(line);
	if (pt != NULL && ret == 0)
	{
		ret = 1;
		ft_puterror("Texture is already assigned !\n");
	}
	while (ft_isspace((int)line[i]) == 1)
		i++;
	if (ret == 0)
		ft_malloc(data, c, &line[i]);
	if (c == 'N' && ret == 0)
		ret = ft_copy(data->pt_no, &line[i]);
	if (c == 'O' && ret == 0)
		ret = ft_copy(data->pt_so, &line[i]);
	if (c == 'W' && ret == 0)
		ret = ft_copy(data->pt_we, &line[i]);
	if (c == 'E' && ret == 0)
		ret = ft_copy(data->pt_ea, &line[i]);
	if (c == 'S' && ret == 0)
		ret = ft_copy(data->pt_sp, &line[i]);
	return (ret);
}

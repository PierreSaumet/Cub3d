/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/07/22 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 5 functions:
**  - 'quit(char *error_msg)':  get a string (error message), use ft_puterror
**  and eixt the program.
**  - 'ft_puterror(char *str)': display the string.
*/

void			ft_puterror(char *str)
{
	if (!str)
		return ;
	write(1, "ERROR !\n\t", 9);
	write(1, str, strlen(str));
}

int				ft_puterror2(char *str)
{
	if (!str)
		return (1);
	write(1, "ERROR !\n\t", 9);
	write(1, str, strlen(str));
	return (1);
}

void			quit(char *error_msg)
{
	if (error_msg)
		ft_puterror(error_msg);
	exit(EXIT_FAILURE);
}

int				ft_strcmp(char *dst, char *src)
{
	int			i;

	i = 0;
	while (dst[i] != '\0' && src[i] != '\0')
	{
		if (dst[i] == src[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int				ft_check_empty(char **argv)
{
	int			fd;
	int			ret;
	char		*buf;
	int			count;

	fd = open(argv[1], O_RDONLY);
	buf = NULL;
	ret = 0;
	count = 0;
	while ((ret = get_next_line(fd, &buf)) >= 1)
	{
		free(buf);
		count++;
	}
	free(buf);
	buf = NULL;
	close(fd);
	if (count == 0)
		return (ft_puterror2("The file is empty\n"));
	return (0);
}

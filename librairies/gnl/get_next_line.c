/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:00:39 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:06:56 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/headers/get_next_line.h"

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\n')
		return ((char *)s + i);
	return (0);
}

void	ft_free(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int		ft_gnl(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if ((*s)[0] == '\0')
			ft_free(s);
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		ft_free(s);
		s = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[1024];
	char		buffer[125 + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, 125)) > 0)
	{
		if (ft_check_ret(line, ret) == 0)
			return (0);
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd]))
			break ;
	}
	return (ft_final_check(str, line, ret, fd));
}

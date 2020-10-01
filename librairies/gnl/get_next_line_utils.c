/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:25:39 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:07 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/headers/get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(s2 = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *src, int s, int len)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	if (ft_strlen(src) < s)
		return (ft_strdup(""));
	if (!(dst = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i + s];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
	return (str);
}

int		ft_final_check(char **s, char **line, int ret, int fd)
{
	int		i;

	i = 0;
	if (ret < 0)
		i = -1;
	else if (ret == 0 && s[fd] == NULL)
	{
		i = 0;
		ft_free(line);
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

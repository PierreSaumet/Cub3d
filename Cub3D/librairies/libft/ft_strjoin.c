/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:19:24 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 18:07:22 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

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


/*
int		ft_len(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_mymalloc(char *res, int i, int j)
{
	if (!(res = malloc(sizeof(char *) * (i + j + 1))))
		return (NULL);
	return (res);
}

char	*ft_end(char *res, int k, int l)
{
	res[k + l + 1] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*res;

	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	i = ft_len(s1);
	j = ft_len(s2);
	k = 0;
	l = 0;
	if (!(res = malloc(sizeof(char *) * (i + j + 1))))
		return (NULL);
	while (k <= i)
	{
		res[k] = s1[k];
		k++;
	}
	while (l <= j)
	{
		res[k + l - 1] = s2[l];
		l++;
	}
	return (ft_end(res, k, l));
}*/

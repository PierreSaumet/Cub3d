/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:22:03 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:22:09 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_mystrlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_mystrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_mystrncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	char	*tab;

	if (s == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_mystrchr(set, s[i]) != NULL)
		i++;
	j = ft_mystrlen((char *)&s[i]);
	if (j != 0)
		while (s[i + j - 1] && ft_mystrchr(set, s[i + j - 1]) != NULL)
			j--;
	if (!(tab = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	tab = ft_mystrncpy(tab, (char *)&s[i], j);
	tab[j] = '\0';
	return (tab);
}

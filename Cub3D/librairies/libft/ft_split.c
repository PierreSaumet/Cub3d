/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:18:18 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:18:23 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_count(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			continue;
		}
		count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_mystrdup(const char *s, int n)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	*ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	k = ft_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	k = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if ((tab[k++] = ft_mystrdup(&s[j], i)) == NULL)
			return (ft_free(tab));
		j += i - 1;
	}
	tab[k] = NULL;
	return (tab);
}

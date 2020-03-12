/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:13:55 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:31:55 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_intlen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_convert(char *str, unsigned int m, int j, int n)
{
	while (m >= 10)
	{
		str[j - 1] = (char)(m % 10 + 48);
		j--;
		m /= 10;
	}
	str[j - 1] = (char)(m % 10 + 48);
	if (n < 0)
		str[j - 2] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				j;
	unsigned int	m;

	i = ft_intlen(n);
	if (n < 0)
	{
		m = -1 * n;
		j = ft_intlen(m) + 1;
		i = j;
		if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
			return (0);
	}
	else
	{
		j = ft_intlen(n);
		m = n;
		if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
			return (0);
	}
	ft_convert(str, m, j, n);
	str[i] = '\0';
	return (str);
}

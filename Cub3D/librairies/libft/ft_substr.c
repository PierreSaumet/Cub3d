/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:22:25 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 18:05:17 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrsp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:18:34 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 18:13:43 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/headers/libft.h"


char	*ft_strchrsp(const char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return ((char *)str);
		str++;
	}
	if (*str == ' ')
		return ((char *)str);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:16:12 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:16:14 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*dst3;
	unsigned char	*src2;
	unsigned char	*src3;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst2 < src2)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	else
	{
		src3 = src2 + (len - 1);
		dst3 = dst2 + (len - 1);
		while (len--)
			*dst3-- = *src3--;
	}
	return (dst);
}

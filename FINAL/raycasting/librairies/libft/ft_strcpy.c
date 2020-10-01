/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/headers/libft.h"

char        *ft_strcpy(char *dst, char *src)
{
    char    *str;
    int     i;

    str = dst;
    i = 0;
    while(src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:13:44 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:22:23 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int count;

	count = 0;
	while (s1[count] == s2[count]
			&& s1[count] && s2[count])
		count++;
	return (s1[count] - s2[count]);
}

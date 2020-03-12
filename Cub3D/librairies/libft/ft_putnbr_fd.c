/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:17:29 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:17:31 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_ptchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int i;

	i = n;
	if (i < 0)
	{
		ft_ptchar('-', fd);
		i = -i;
	}
	if (i >= 0 && i < 10)
		ft_ptchar(i + '0', fd);
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_ptchar((i % 10) + '0', fd);
	}
}

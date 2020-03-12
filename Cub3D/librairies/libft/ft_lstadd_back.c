/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:33:19 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:20:00 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst != NULL && new != NULL)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}

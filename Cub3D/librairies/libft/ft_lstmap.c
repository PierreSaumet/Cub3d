/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:13:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 15:34:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (0);
	if (!(tmp = ft_lstnew(f(lst->content))))
		return (0);
	list = tmp;
	while (lst)
	{
		if (lst->next)
		{
			if (!(tmp->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&list, del);
				return (0);
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	tmp->next = NULL;
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:14:11 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/30 20:14:31 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*changed;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		changed = ft_lstnew(f(lst->content));
		if (!changed)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, changed);
		lst = lst -> next;
	}
	return (new);
}

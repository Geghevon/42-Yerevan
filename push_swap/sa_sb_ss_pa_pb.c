/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:29:39 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:29:43 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, char c)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, char c)
{
	int	tmp;

	if (!b || !b->next)
		return ;
	tmp = b->index;
	b->index = b->next->index;
	b->next->index = tmp;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(&a, 's');
	sb(b, 's');
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_putstr_fd("pb\n", 1);
}

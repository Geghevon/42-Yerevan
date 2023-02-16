/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:27:27 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:27:32 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, char c)
{
	t_stack	*add;
	t_stack	*addto;

	add = *a;
	*a = (*a)->next;
	addto = bot(*a);
	add->next = NULL;
	addto->next = add;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, char c)
{
	t_stack	*add;
	t_stack	*addto;

	add = *b;
	*b = (*b)->next;
	addto = bot(*b);
	add->next = NULL;
	addto->next = add;
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 'r');
	rb(b, 'r');
	ft_putstr_fd("rr\n", 1);
}

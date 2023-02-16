/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:30:52 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:30:54 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_stack **a, t_helping *t)
{
	if ((*a)->index == t->end)
		ra(a, 'a');
	else if ((*a)->next->index == t->end)
		rra(a, 'a');
	if ((*a)->index > (*a)->next->index)
		sa(a, 'a');
}

void	pb_except(t_stack **a, t_stack **b, t_helping *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (t->ssize > 6)
	{
		while (i < t->ssize && j < t->ssize / 2)
		{
			if ((*a)->index <= t->ssize / 2)
			{
				pb(a, b);
				j++;
			}
			else
				ra(a, 'a');
			i++;
		}
	}
	while (t->ssize - j > 3)
	{
		pb(a, b);
		j++;
	}
}

int	mod(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	ft_end(t_stack *a, t_helping *t)
{
	t->end = a->index;
	while (a)
	{
		if (a->index > t->end)
			t->end = a->index;
		a = a->next;
	}
}

void	sorting(t_stack **a, t_stack **b, t_helping *t)
{
	pb_except(a, b, t);
	ft_end(*a, t);
	sorting_three(a, t);
	while (*b)
	{
		final_pos(a, b);
		move(a, b);
		move_choice(a, b);
	}
	if (check_sorted_for_stack(*a))
		move_st(a, t);
}

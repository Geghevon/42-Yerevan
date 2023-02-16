/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:14:14 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:14:16 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	poses(t_stack **t)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *t;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	fifinal_pos(t_stack **a, int ind, int find, int fpos)
{
	t_stack	*t;

	t = *a;
	while (t)
	{
		if (t->index > ind && t->index < find)
		{
			find = t->index;
			fpos = t->position;
		}
		t = t->next;
	}
	if (find != INT_MAX)
		return (fpos);
	t = *a;
	while (t)
	{
		if (t->index < find)
		{
			find = t->index;
			fpos = t->position;
		}
		t = t->next;
	}
	return (fpos);
}

void	final_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	poses(a);
	poses(b);
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->final_pos = fifinal_pos(a, tmp_b->index, INT_MAX, 0);
		tmp_b = tmp_b->next;
	}
}

int	find_start_index(t_stack **a)
{
	t_stack	*t;
	int		start;
	int		start_pos;

	t = *a;
	start = INT_MAX;
	poses(a);
	start_pos = t->position;
	while (t)
	{
		if (t->index < start)
		{
			start = t->index;
			start_pos = t->position;
		}
		t = t->next;
	}
	return (start_pos);
}

void	move_st(t_stack **a, t_helping *t)
{
	t->start = find_start_index(a);
	t->ssize = ft_size(*a);
	if (t->start > t->ssize / 2)
	{
		while (t->start < t->ssize)
		{
			rra(a, 'a');
			t->start++;
		}
	}
	else
	{
		while (t->start > 0)
		{
			ra(a, 'a');
			t->start--;
		}
	}
}

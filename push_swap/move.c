/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:07 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:09:11 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **a, t_stack **b)
{
	int		a_s;
	int		b_s;
	t_stack	*t_a;
	t_stack	*t_b;

	t_a = *a;
	t_b = *b;
	a_s = ft_size(t_a);
	b_s = ft_size(t_b);
	while (t_b)
	{
		t_b->b_move = t_b->position;
		if (t_b->b_move > b_s / 2)
			t_b->b_move = (b_s - t_b->b_move) * -1;
		t_b->a_move = t_b->final_pos;
		if (t_b->final_pos > b_s / 2)
			t_b->a_move = (a_s - t_b->final_pos) * -1;
		t_b = t_b->next;
	}
}

void	move_choice(t_stack **a, t_stack **b)
{
	t_stack	*t;
	int		move;
	int		a_move;
	int		b_move;

	t = *b;
	move = INT_MAX;
	while (t)
	{
		if (mod(t->a_move) + mod(t->b_move) < mod(move))
		{
			move = (mod(t->a_move) + mod(t->b_move));
			a_move = t->a_move;
			b_move = t->b_move;
		}
		t = t->next;
	}
	moving(a, b, a_move, b_move);
}

void	moving(t_stack **a, t_stack **b, int a_move, int b_move)
{
	if (a_move < 0 && b_move < 0)
		to_rr_rrr(a, b, &a_move, &b_move);
	else if (a_move > 0 && b_move > 0)
		to_rr_rrr(a, b, &a_move, &b_move);
	to_ra(a, &a_move);
	to_rb(b, &b_move);
	pa(b, a);
}

void	to_rr_rrr(t_stack **a, t_stack **b, int *a_move, int *b_move)
{
	if (*a_move < 0 && *b_move < 0)
	{
		while (*a_move < 0 && *b_move < 0)
		{
			(*a_move)++;
			(*b_move)++;
			rrr(a, b);
		}
	}
	else if (*a_move > 0 && *b_move > 0)
	{
		while (*a_move > 0 && *b_move > 0)
		{
			(*a_move)--;
			(*b_move)--;
			rr(a, b);
		}
	}
}

void	to_ra(t_stack **a, int *a_move)
{
	while (*a_move)
	{
		if (*a_move > 0)
		{
			ra(a, 'a');
			(*a_move)--;
		}
		else if (*a_move < 0)
		{
			rra(a, 'a');
			(*a_move)++;
		}
	}
}

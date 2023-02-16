/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:56:19 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 16:56:21 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(t_stack **a, t_stack **b, t_helping *t)
{
	free_stack(a);
	free_stack(b);
	if (t->numbers)
		free(t->numbers);
	if (t->sonum)
		free(t->sonum);
	if (t->pos)
		free(t->pos);
}

void	free_stack(t_stack **t)
{
	t_stack	*t_t;

	if (!t || !(*t))
		return ;
	while (*t)
	{
		t_t = (*t)->next;
		free(*t);
		*t = t_t;
	}
	*t = NULL;
}

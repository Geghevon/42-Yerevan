/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:12:58 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:13:01 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numbers_cpy(int ac, t_helping *t)
{
	int	i;

	t->sonum = malloc(sizeof(int) * (ac - 1));
	if (!t->sonum)
		error("Error\n", NULL, NULL, t);
	i = 0;
	while (i < ac - 1)
	{
		t->sonum[i] = t->numbers[i];
		i++;
	}
	return (0);
}

int	usualsort(int ac, t_helping *t)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < ac - 2)
	{
		if (t->sonum[i] > t->sonum[i + 1])
		{
			tmp = t->sonum[i];
			t->sonum[i] = t->sonum[i + 1];
			t->sonum[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (0);
}

int	get_pos(int ac, t_helping *t)
{
	int	i;
	int	j;

	t->pos = malloc(sizeof(int) * (ac - 1));
	if (!t->pos)
		error("Error\n", NULL, NULL, t);
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (t->numbers[i] != t->sonum[j])
			j++;
		t->pos[i] = j;
		i++;
	}
	return (0);
}

t_stack	*init_filling(t_helping *t, t_stack *a, int ac)
{
	int	i;

	a = NULL;
	i = 0;
	while (i < ac - 1)
	{
		if (i == 0)
			a = new(t->numbers[i]);
		else
			back_add(&a, new(t->numbers[i]));
		i++;
	}
	t->ssize = ft_size(a);
	return (a);
}

int	filling_indexes(t_helping *t, t_stack *a)
{
	int	i;

	i = 0;
	while (i < t->ssize && a)
	{
		a->index = t->pos[i];
		a = a->next;
		i++;
	}
	return (0);
}

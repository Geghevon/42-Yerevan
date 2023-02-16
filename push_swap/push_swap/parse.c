/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:11:56 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:11:59 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_two(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] == ' ')
				return (1);
			i++;
		}
	}
	return (0);
}

int	counting_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	to_rb(t_stack **b, int *b_move)
{
	while (*b_move)
	{
		if (*b_move > 0)
		{
			rb(b, 'b');
			(*b_move)--;
		}
		else if (*b_move < 0)
		{
			rrb(b, 'b');
			(*b_move)++;
		}
	}
}

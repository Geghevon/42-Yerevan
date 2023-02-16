/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:07:01 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:31:55 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(int argc, char **argv, t_helping *t)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	number_check(argc, argv);
	max_min_check(argc, argv);
	t->numbers = malloc(sizeof(int) * (argc - 1));
	if (!t->numbers)
		error("Error\n", NULL, NULL, t);
	return (0);
}

int	check_sorted_for_stack(t_stack *a)
{
	while (a->next)
	{
		if (a->index > a->next->index)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_sorted(int ac, t_helping *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 2)
	{
		if (t->numbers[i] < t->numbers[i + 1])
			j++;
		i++;
	}
	if (j == i)
	{
		frees(NULL, NULL, t);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	push_swap(t_stack **a, t_stack **b, t_helping *t)
{
	t_stack	*tmp;

	if (t->ssize == 2)
		sa(a, 'a');
	tmp = *a;
	t->end = tmp->index;
	while (tmp)
	{
		if (tmp->index > t->end)
			t->end = tmp->index;
		tmp = tmp->next;
	}
	if (t->ssize == 3)
		sorting_three(a, t);
	else if (t->ssize > 3)
		sorting(a, b, t);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_helping	t;

	if (check_two(argc, argv))
	{
		argv = ft_split(argv[1], ' ');
		argc = counting_args(argv);
	}
	check_arg(argc, argv, &t);
	fill_numbers(argc, argv, &t);
	dup_check(argc, &t);
	check_sorted(argc, &t);
	a = NULL;
	a = init_filling(&t, a, argc);
	b = NULL;
	numbers_cpy(argc, &t);
	usualsort(argc, &t);
	get_pos(argc, &t);
	filling_indexes(&t, a);
	push_swap(&a, &b, &t);
	frees(&a, &b, &t);
	return (0);
}

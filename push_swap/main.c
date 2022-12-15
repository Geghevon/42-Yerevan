#include "push_swap.h"

int	check_arg(int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	return (0);
}

int	check_sorted(int ac, t_helping *t)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		if(t->numbers[i] < t->numbers[i + 1])
			j++;
		i++;
	}
	if(j == i - 1)
	{
		free(t->numbers);
		exit(EXIT_SUCCESS);
	}
	return(0);
}

static void	push_swap(t_stack **a, t_stack **b, t_helping *t)
{
	t_stack *tmp;
	if(t->ssize == 2)
		sa(a, 'a');
	tmp = *a;
	t->end = tmp->index;
	while(tmp)
	{
		if(tmp->index > t->end)
			t->end = tmp->index;
		tmp = tmp->next;
	}
	if(t->ssize == 3)
		sorting_three(a, t);
	else if(t->ssize > 3)
		sorting(a, b, t);
}

int main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_helping	t;

	check_arg(argc, argv);
	number_check(argc, argv);
	max_min_check(argc, argv);
	t.numbers = malloc(sizeof(int) * (argc - 1));
	if(!t.numbers)
		error("Memory error");
	fill_numbers(argc, argv, &t);
	dup_check(argc, argv, &t);
	check_sorted(argc, &t);
	a = init_filling(&t, a, argc);
	b = NULL;
	numbers_cpy(argc, &t);
	usualsort(argc, &t);
	get_pos(argc, &t);
	filling_indexes(&t, a, argc);
	push_swap(a, b , &t);
}
#include "push_swap.h"

int	numbers_cpy(int ac, t_helping *t)
{
	int i;

	t->sonum = malloc(sizeof(int) * (ac - 1));
	if(!t->sonum)
	{
		free(t->numbers);
		error("Memory error");
	}
	i = 0;
	while (i < ac - 1)
	{
		t->sonum[i] = t->numbers[i];
		i++;
	}
	return(0);
}

int usualsort(int ac, t_helping *t)
{
	int	tmp;
	int i;

	i = 0;
	while(i < ac - 2)
	{
		if(t->sonum[i] > t->sonum[i + 1])
		{
			tmp = t->sonum[i];
			t->sonum[i] = t->sonum[i + 1];
			t->sonum[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return(0);
}

int get_pos(int ac, t_helping *t)
{
	int	i;
	int	j;

	t->pos = malloc(sizeof(int) * (ac - 1));
	if(!t->pos)
	{
		free(t->numbers);
		free(t->pos);
		error("Memory error");
	}
	i = 0;
	while(i < ac - 1)
	{
		j = 0;
		while(t->numbers[i] != t->sonum[j])
			j++;
		t->pos[i] = j;
		i++;
	}
	return (0);
}

int	init_filling(t_helping *t, t_stack *a, int ac)
{
	int	i;

	a = NULL;
	i = 0;
	while(i < ac - 1)
	{
		if(i == 0)
			a = new(t->numbers[i]);
		else
			back_add(&a, new(t->numbers[i]));
		i++;
	}
	t->ssize = ft_size(a);
	return(0);
}

int	filling_indexes(t_helping *t, t_stack *a, int ac)
{
	t_stack	*p;
	int		i;

	i = 0;
	while (i < t->ssize && a)
	{
		a->index = t->pos[i];
		a = a->next;
		i++;
	}
	return(0);
}
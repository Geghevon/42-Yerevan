#include "push_swap.h"

void    sorting_three(t_stack **a, t_helping *t)
{
	if((*a)->index == t->end)
		ra(a, 'a');
	else if((*a)->next->index == t->end)
		rra(a, 'a');
	if((*a)->index > (*a)->next->index)
		sa(*a, 'a');
}

static void	pb_except(t_stack **a, t_stack **b, t_helping *t)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if(t->ssize > 6)
	{
		while(i < t->ssize && j < t->ssize / 2)
		{
			if((*a)->index <= t->ssize / 2)
			{
				pb(a, b);
				j++;
			}
			else
				ra(a, 'a');
			i++;
		}
	}
	while(t->ssize - j > 3)
	{
		pb(a, b);
		j++;
	}
}

void    sorting(t_stack **a, t_stack **b, t_helping *t)
{
	pb_except(a, b, t);
	sorting_three(a, t);
}
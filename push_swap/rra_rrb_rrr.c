#include "push_swap.h"

static void	rra(t_stack **a, char c)
{
	t_stack *add;
	t_stack	*addto;
	t_stack	*onbot;

	onbot = on_bot(*a);
	add = bot(*a);
	addto = *a;
	*a = add;
	(*a)->next = addto;
	onbot->next = NULL;
	if(c == 'a')
		ft_putstr_fd("rra\n", 1);
}

static void	rrb(t_stack **b, char c)
{
	t_stack *add;
	t_stack	*addto;
	t_stack	*onbot;

	onbot = on_bot(*b);
	add = bot(*b);
	addto = *b;
	*b = add;
	(*b)->next = addto;
	onbot->next = NULL;
	if(c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

static void rrr(t_stack **a, t_stack **b)
{
	rra(a, 'r');
	rrb(b, 'r');
	ft_putstr_fd("rrr\n", 1);
}
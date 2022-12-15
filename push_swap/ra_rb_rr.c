#include "push_swap.h"

static void	ra(t_stack **a, char c)
{
	t_stack *add;
	t_stack	*addto;

	add = *a;
	*a = (*a)->next;
	addto = bot(*a);
	add->next = NULL;
	addto->next = add;
	if(c == 'a')
		ft_putstr_fd("ra\n", 1);
}

static void	rb(t_stack **b, char c)
{
	t_stack *add;
	t_stack	*addto;

	add = *b;
	*b = (*b)->next;
	addto = bot(*b);
	add->next = NULL;
	addto->next = add;
	if(c == "b")
		ft_putstr_fd("rb\n", 1);
}

static void rr(t_stack **a, t_stack **b)
{
	ra(a, 'r');
	rb(b, 'r');
	ft_putstr_fd("rr\n", 1);
}
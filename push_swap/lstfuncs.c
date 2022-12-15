#include "push_swap.h"

t_stack	*bot(t_stack *t)
{
	while(t && t->next)
		t = t->next;
	return(t);
}

t_stack *on_bot(t_stack *t)
{
	while(t && t->next && t->next->next)
		t = t->next;
	return(t);
}

t_stack *new(int content)
{
	t_stack	*t;

	t = malloc(sizeof * t);
	if(!t)
		return(NULL);
	t->content = content;
	t->index = 0;
	t->final_pos = -1;
	t->position = -1;
	t->a_move = -1;
	t->b_move = -1;
	t->next = NULL;
	return(t);
}

void back_add(t_stack **t, t_stack *add)
{
	t_stack	*curr;
	
	if(!add)
		return ;
	if(!*t)
	{
		*t = add;
		return ; 
	}
	curr = bot(*t);
	curr->next = add;
}

int	ft_size(t_stack *t)
{
	int	count;

	count = 0;
	if (!t)
		return (0);
	while (t)
	{
		t = t->next;
		count++;
	}
	return (count);
}
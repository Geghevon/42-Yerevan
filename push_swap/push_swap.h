#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int			content;
	int			position;
	int			index;
	int			final_pos;
	int			a_move;
	int			b_move;
	struct s_stack	*next;
}			t_stack;

typedef struct s_helping
{
	int 	*numbers;
	int		*pos;
	int		*sonum;
	int		end;
	int		ssize;
}			t_helping;

int	error(char *str);
t_stack	*bot(t_stack *t);
t_stack *on_bot(t_stack *t);
t_stack *new(int content);
void back_add(t_stack **t, t_stack *add);
int	ft_size(t_stack *t);
int	check_arg(int argc, char **argv);
int	check_sorted(int ac, t_helping *t);
static void	push_swap(t_stack *a, t_stack *b, t_helping *t);
int main(int argc, char **argv);
int number_check(int ac, char **av);
int max_min_check(int ac, char **av);
int	fast_check(long	num, int neg);
int	fill_numbers(int ac, char **av, t_helping *t);
int	dup_check(int ac, char **argv, t_helping *t);
int	numbers_cpy(int ac, t_helping *t);
int usualsort(int ac, t_helping *t);
int get_pos(int ac, t_helping *t);
int	init_filling(t_helping *t, t_stack *a, int ac);
int	filling_indexes(t_helping *t, t_stack *a, int ac);
static void	ra(t_stack **a, char c);
static void	rb(t_stack **b, char c);
static void rr(t_stack **a, t_stack **b);
static void	rra(t_stack **a, char c);
static void	rrb(t_stack **b, char c);
static void rrr(t_stack **a, t_stack **b);
static void sa(t_stack *a, char c);
static void	sb(t_stack *b, char c);
void ss(t_stack *a, t_stack *b);
static void	pa(t_stack **b, t_stack **a);
static void	pb(t_stack **a, t_stack **b);
#endif
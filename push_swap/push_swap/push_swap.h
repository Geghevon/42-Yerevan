/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:25:26 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 17:26:46 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				position;
	int				index;
	int				final_pos;
	int				a_move;
	int				b_move;
	struct s_stack	*next;
}			t_stack;

typedef struct s_helping
{
	int	*numbers;
	int	*pos;
	int	*sonum;
	int	end;
	int	ssize;
	int	start;
}			t_helping;

t_stack	*bot(t_stack *t);
t_stack	*new(int content);
t_stack	*on_bot(t_stack *t);
t_stack	*init_filling(t_helping *t, t_stack *a, int ac);

int		mod(int i);
int		ft_size(t_stack *t);
int		counting_args(char **av);
int		main(int argc, char **argv);
int		check_two(int ac, char **av);
int		find_start_index(t_stack **a);
int		get_pos(int ac, t_helping *t);
int		fast_check(long num, int neg);
int		usualsort(int ac, t_helping *t);
int		number_check(int ac, char **av);
int		dup_check(int ac, t_helping *t);
int		max_min_check(int ac, char **av);
int		numbers_cpy(int ac, t_helping *t);
int		check_sorted(int ac, t_helping *t);
int		check_sorted_for_stack(t_stack *a);
int		filling_indexes(t_helping *t, t_stack *a);
int		fill_numbers(int ac, char **av, t_helping *t);
int		check_arg(int argc, char **argv, t_helping *t);
int		fifinal_pos(t_stack **a, int ind, int find, int fpos);
int		error(char *str, t_stack **a, t_stack **b, t_helping *t);

void	poses(t_stack **t);
void	sb(t_stack *b, char c);
void	sa(t_stack **a, char c);
void	free_stack(t_stack **t);
void	ra(t_stack **a, char c);
void	rb(t_stack **b, char c);
void	rra(t_stack **a, char c);
void	rrb(t_stack **b, char c);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	move(t_stack **a, t_stack **b);
void	to_rb(t_stack **b, int *b_move);
void	to_ra(t_stack **a, int *a_move);
void	ft_end(t_stack *a, t_helping *t);
void	back_add(t_stack **t, t_stack *add);
void	move_st(t_stack **a, t_helping *t);
void	final_pos(t_stack **a, t_stack **b);
void	move_choice(t_stack **a, t_stack **b);
void	sorting_three(t_stack **a, t_helping *t);
void	frees(t_stack **a, t_stack **b, t_helping *t);
void	sorting(t_stack **a, t_stack **b, t_helping *t);
void	pb_except(t_stack **a, t_stack **b, t_helping *t);
void	push_swap(t_stack **a, t_stack **b, t_helping *t);
void	moving(t_stack **a, t_stack **b, int a_move, int b_move);
void	to_rr_rrr(t_stack **a, t_stack **b, int *a_move, int *b_move);

#endif

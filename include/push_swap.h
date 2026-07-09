/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:58:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TOTAL
}	t_op;

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
	t_strategy	strategy_arg;
	t_strategy	strategy_used;
	double		disorder;
	int			bench;
	int			*ops;
}	t_stack;


//ERRORS
int			ft_return_error(int print);
int			ft_exit_error(int code);

//PARSE UTILS
int			ft_valid_args(char **argv_split);
int			ft_parse_pushswap(t_stack **a, char **argv_split);
int			ft_parse_flags(t_stack *a, char **split);
int			ft_parse_integers(t_stack *a, char **split);
char		*ft_strjoin_args(int argc, char **argv);
char		*ft_strjoin_sep(char *prev, char *src);
void		ft_free_split(char **split);
int			ft_setflag_ps(t_stack *a, char *str);
int			ft_isflag_ps(char *str);
int			ft_valid_istr(char *istr);
double		ft_compute_disorder(t_stack *stack);
long		ft_atol(char *str);

//STACK UTILS
t_node		*ft_node_new(int value);
t_stack		*ft_stack_new(int create_ops);
void		ft_free_stack(t_stack *stack);
void		ft_print_stack(t_stack *stack);
void		ft_stack_index(t_stack **stack);
int			ft_stacksize(t_stack *stack);
int			ft_stacksorted(t_stack *stack);
t_node		*ft_stacklast(t_stack *stack);
void		ft_stack_setstrategies(t_stack *a, char *s1, char *s2);
void		ft_stack_setnames(t_stack *a, char *s1, char *s2);
int			ft_stack_init(t_stack *stack);
void		ft_stack_init_numbers(t_stack *a, int *numbers, int size);
void		ft_stackadd_back(t_stack *stack, t_node *node);
void		ft_stackadd_front(t_stack *stack, t_node *node);
int			stack_find_index(t_stack *stack, int index);
int			stack_find_pos(t_stack *stack, t_node *node);
void		stack_index_to_top(t_stack *stack, int index, char stack_name);
t_node		*find_smallest(t_stack *stack);

//BENCH_UTILS
void		ft_print_bench(t_stack *stack);

//SORT
void		ft_sort_four(t_stack *a, t_stack *b);
void		ft_sort_five(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *stack);
void		ft_sort_strategy(t_stack **a, t_stack **b);
void		ft_sort_units(t_stack *a, t_stack *b);

//SORT SIMPLE
void		ft_sort_simple(t_stack *a, t_stack *b);

//SORT MEDIUM
void		ft_sort_medium(t_stack *a, t_stack *b);

//SORT COMPLEX
void		ft_sort_complex(t_stack *a, t_stack *b);

////SORT SIMPLE - METADATA
t_node		*find_cheapest(t_stack *stack);
void		update_positions(t_stack *stack);
void		update_targets_a(t_stack *a, t_stack *b);
void		update_targets_b(t_stack *a, t_stack *b);
void		assign_indexes(t_stack *stack);
void		update_costs(t_stack *a, t_stack *b);

//SORT UTILS
int			ft_max_index(t_stack *stack);
int			ft_min_index(t_stack *stack);
void		rotate_to_top(t_stack *stack, t_node *target, char name);
int			int_sqrt(int n);

//OPERATIONS
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_sa(t_stack *a);
void		ft_sb(t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

void		ft_push(t_stack *dest, t_stack *src);
void		ft_swap(t_stack *stack);
void		ft_rotate(t_stack *stack);
void		ft_reverse(t_stack *stack);

#endif
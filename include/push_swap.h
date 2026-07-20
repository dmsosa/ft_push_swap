/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 14:56:24 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
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
	char		name;
	t_strategy	strategy_arg;
	t_strategy	strategy_used;
	double		disorder;
	int			bench;
	int			*ops;
}	t_stack;

//ERRORS
int			ft_return_error(int print);
void		ft_exit_error(int code);

//PARSE UTILS
char		**split_arguments(int argc, char **argv);
int			ft_valid_args(char **argv_split);
int			ft_parse_pushswap(t_stack **a, t_stack **b, char **argv_split);
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
t_stack		*ft_stack_new(char name, int *ops);
void		ft_free_stack(t_stack *stack);
void		ft_print_stack(t_stack *stack);
void		ft_stack_index(t_stack **stack);
int			ft_stacksize(t_stack *stack);
int			ft_stacksorted(t_stack *stack);
t_node		*ft_stacklast(t_stack *stack);
void		ft_stack_setstrategies(t_stack *a, char *s1, char *s2);
void		ft_stack_setnames(t_stack *a, char *s1, char *s2);
int			ft_stack_init(t_stack *stack);
void		ft_stack_add_numbers(t_stack *a, int *numbers, int size);
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

//SORT UTILS
void		rotate_to_top(t_stack *stack, t_node *top_node);
void		reverse_rotate_to_top(t_stack *stack, t_node *top_node);
void		rotate_both(t_stack *a, t_stack *b,
				t_node *top_a, t_node *top_b);
void		reverse_rotate_both(t_stack *a, t_stack *b,
				t_node *top_a, t_node *top_b);
void		rotate_pos_top(t_stack *stack, int pos);
t_node		*find_max(t_stack *stack);
int			find_max_pos(t_stack *stack);
t_node		*find_min(t_stack *stack);
void		move_min_to_top(t_stack *a);
void		rotate_to_top(t_stack *stack, t_node *top_node);
void		reverse_rotate_to_top(t_stack *stack, t_node *top_node);
void		rotate_both(t_stack *a, t_stack *b, t_node *top_a,
				t_node *top_b);
void		reverse_rotate_both(t_stack *a, t_stack *b, t_node *top_a,
				t_node *top_b);
void		final_rotation(t_stack *a);

//SORT SIMPLE
void		sort_insertion(t_stack *a, t_stack *b);
void		sort_turk(t_stack *a, t_stack *b);

//SORT MEDIUM
typedef struct s_chunk
{
	int				start;
	int				end;
	int				middle;
}					t_chunk;

int			stack_has_range(t_stack *stack, int start, int end);
int			next_chunk_pos(t_stack *stack, int pivot, int chunk);
bool		node_in_chunk(t_node *node, t_chunk *chunk);
bool		has_chunk_nodes(t_stack *a, t_chunk *chunk);
int			get_chunk_count(int size);
bool		should_rotate_after_push(t_node *node, int middle);
int			get_chunk_size(int size);
static void	process_chunk(t_stack *a, t_stack *b, t_chunk *chunk);
static void	run_chunk(t_stack *a, t_stack *b, int chunk_index, int total_size);
static void	push_chunks(t_stack *a, t_stack *b);
static void	pull_chunks(t_stack *a, t_stack *b);
void		sort_chunk(t_stack *a, t_stack *b);

//SORT COMPLEX
void		sort_radix(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* STACK                                                                      */
/* ************************************************************************** */

//SORT COMPLEX
void		ft_sort_complex(t_stack *a, t_stack *b);

/* ************************************************************************** */
/* METADATA                                                                  */
/* ************************************************************************** */

t_node		*find_min(t_stack *stack);
void		bring_to_top(t_stack *stack, t_node *top_node);
void		move_a_to_b(t_stack *a, t_stack *b);
void		move_b_to_a(t_stack *a, t_stack *b);
void		rotate_to_top(t_stack *stack, t_node *top_node);
void		reverse_rotate_to_top(t_stack *stack, t_node *top_node);
void		rotate_both(t_stack *a, t_stack *b, t_node *top_a,
				t_node *top_b);
void		reverse_rotate_both(t_stack *a, t_stack *b, t_node *top_a,
				t_node *top_b);
void		rotate_pos_top(t_stack *stack, int pos);
void		rotate_index_top(t_stack *stack, int index);

/* ************************************************************************** */
/* METADATA                                                                   */
/* ************************************************************************** */

void		assign_indexes(t_stack *stack);
void		update_positions(t_stack *stack);
void		update_targets_a(t_stack *a, t_stack *b);
void		update_targets_b(t_stack *a, t_stack *b);
void		update_costs_a(t_stack *a, t_stack *b);
void		update_costs_b(t_stack *a, t_stack *b);
void		find_cheapest(t_stack *stack);
t_node		*find_lowest_cost(t_stack *stack);
void		update_metadata_a_to_b(t_stack *a, t_stack *b);
void		update_metadata_b_to_a(t_stack *a, t_stack *b);

//SORT UTILS
int			ft_max_index(t_stack *stack);
int			ft_min_index(t_stack *stack);
t_node		*find_max(t_stack *stack);
int			find_max_pos(t_stack *stack);
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
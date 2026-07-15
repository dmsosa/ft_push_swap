/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:39 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/15 15:02:01 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_rotation(t_stack *stack, t_node *top_node, char stack_name)
{
	while (stack->head != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

static void	rotate_both(t_stack *st1, t_stack *st2, t_node *cheapest)
{
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (st1->head != cheapest && st2->head != cheapest->target)
			ft_rr(st1, st2);
	}
	if (!cheapest->above_median && !cheapest->target->above_median)
	{
		while (st1->head != cheapest && st2->head != cheapest->target)
			ft_rrr(st1, st2);
	}
}

/*
Back to A, the logic is similar but instead, 
the targets (number I need to sit on to)
are the numbers which are one index unit greater than me
so and again my cost depends on my position, my target's pos
and whether we are both above or below the median at the same time.

*/
static void	ft_from_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->size > 0)
	{
		update_positions(a);
		update_positions(b);
		update_targets_b(a, b);
		update_costs(b, a);
		cheapest = find_cheapest(b);
		rotate_both(b, a, cheapest);
		finish_rotation(b, cheapest, 'b');
		finish_rotation(a, cheapest->target, 'a');
		ft_pa(a, b);
	}
}

/*
This algorithm is known as the turk sort, which is goiing to:
1. Push elements from A to B until there are only 3 in A.
2. Stack B is going to be pushed with previous calculations,
with the goal of making stack B to be sorted from greatest to 
smallest. 

Before each push, we calculate:
	a. target of each node 'to_push'.
	b. cost of each node.
	c. return cheapest node.
	d. rotate until cheapest node is on top of A.
	e. rotate until cheapest->target is on top of B.
	f. push A to B.
	g. repeat until there are only 3 elements in A.
	
3. Sort A with sort_three();

4. Push all elements back to A.
5. If minimum of A is not on top, move it to the top.
*/
t_node	*find_lowest_cost(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	if (!stack || !stack->top)
		return (NULL);
	best = stack->top;
	node = best->next;
	while (node)
	{
		if (node->cost < best->cost)
			best = node;
		node = node->next;
	}
	return (best);
}

void	find_cheapest(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	best = find_lowest_cost(stack);
	node = stack->top;
	while (node)
	{
		node->cheapest = (node == best);
		node = node->next;
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_lowest_cost(b);
	target = cheapest->target;
	if (cheapest->above_median && target->above_median)
		rotate_both(a, b, target, cheapest);
	else if (!cheapest->above_median && !target->above_median)
		reverse_rotate_both(a, b, target, cheapest);
	bring_to_top(a, target);
	bring_to_top(b, cheapest);
	pa(a, b);
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_lowest_cost(a);
	target = cheapest->target;
	if (cheapest->above_median && target->above_median)
		rotate_both(a, b, cheapest, target);
	else if (!cheapest->above_median && !target->above_median)
		reverse_rotate_both(a, b, cheapest, target);
	bring_to_top(a, cheapest);
	bring_to_top(b, target);
	pb(a, b);
}

static void	final_rotation(t_stack *a)
{
	t_node	*min;

	min = find_min(a);
	if (min)
		bring_to_top(a, min);
}

void	sort_turk(t_stack *a, t_stack *b)
{
	if (a->size > 3)
		pb(a, b);
	if (a->size > 3)
		pb(a, b);
	while (a->size > 3)
	{
		update_metadata_a_to_b(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (b->size)
	{
		update_metadata_b_to_a(a, b);
		move_b_to_a(a, b);
	}
	update_positions(a);
	stack_index_to_top(a, 0, 'a');
}

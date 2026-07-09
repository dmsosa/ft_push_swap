/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:39 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 16:49:25 by durisosa         ###   ########.fr       */
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
		update_targets_b(a, b);
		update_positions(a);
		update_positions(b);
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
void	ft_sort_simple(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	ft_pb(a, b);
	ft_pb(a, b);
	while (a->size > 3)
	{
		update_targets_a(a, b);
		update_positions(a);
		update_positions(b);
		update_costs(a, b);
		cheapest = find_cheapest(a);
		rotate_both(a, b, cheapest);
		finish_rotation(a, cheapest, 'a');
		finish_rotation(b, cheapest->target, 'b');
		ft_pb(a, b);
	}
	ft_sort_three(a);
	ft_from_b_to_a(a, b);
	stack_index_to_top(a, 0, 'a');
}

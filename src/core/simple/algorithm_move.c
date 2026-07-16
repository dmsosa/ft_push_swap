/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:00:46 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 20:37:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack *stack, t_node *top_node, char name)
{
	if (stack->head == top_node)
		return ;
	if (top_node->above_median)
		rotate_to_top(stack, top_node, name);
	else
		reverse_rotate_to_top(stack, top_node, name);
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
	bring_to_top(a, target, 'a');
	bring_to_top(b, cheapest, 'b');
	ft_pa(a, b);
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
	bring_to_top(a, cheapest, 'a');
	bring_to_top(b, target, 'b');
	ft_pb(a, b);
}

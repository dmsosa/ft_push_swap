/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 23:19:14 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/09 14:48:31 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotation_cost(t_stack *stack, t_node *node)
{
	if (node->above_median)
		return (node->position);
	return (stack->size - node->position);
}

/* 
Cost of current node is:
max_of(pos_a, pos_b) IF current.above_median == target.above_median,
for this to work I need to update targets before the positions.

else if current->above_median != current->target->above_median
return their sum. 

*/
void	update_costs(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		if (node->above_median == node->target->above_median)
		{
			if (node->position > node->target->position)
				node->cost = node->position;
			else
				node->cost = node->target->position;
		}
		else
			node->cost = node->position + node->target->position;
		node = node->next;
	}
}

/*
SUGGESTION: 
update costs can be abstracted to use dest and src stacks
rather than hardcoding a and b.
Also, if both are above or below median at the same time,
returning the maximum of their positions is more profitable
than always returning their sum, that way we can also use rrr
to rotate both at the same time.

void	update_costs(t_stack *dst, t_stack *src)
{
	t_node	*node;

	cost = dst->head;
	while (cost)
	{
		if (cost->above_median && cost->target->above_median)
			cost->cost = ft_max(cost->position, cost->target->position);
		else if (cost->above_median)
			cost->cost = cost->position + b->size - cost->target->position;
		else if (cost->target->above_median)
			cost->cost = a->size - cost->position + cost->target->position;
		else
			cost->cost = ft_max(a->size - cost->position,
					b->size - cost->target->position);
		cost->next;
	}
}
*/



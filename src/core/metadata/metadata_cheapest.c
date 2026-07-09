/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_cheapest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:15:18 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/06 16:16:09 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_lowest_cost(t_stack *stack)
{

}

t_node	*find_cheapest(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	if (!stack->head)
		return (NULL);
	best = stack->head;
	node = best->next;
	while (node)
	{
		if (node->cost < best->cost)
			best = node;
		node = node->next;
	}
	return (best);
}
/*
PREVIOUS
find_cheapest is returning void, it would be better
to return the cheapest node directly.

void	find_cheapest(t_stack *stack)
{
	t_node	*node;
	t_node	*best;

	best = find_lowest_cost(stack);
	node = stack->head;
	while (node)
	{
		node->cheapest = (node == best);
		node = node->next;
	}
}
*/


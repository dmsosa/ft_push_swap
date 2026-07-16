/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:15:26 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 15:09:43 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_smallest_unindexed(t_stack *stack)
{
	t_node	*node;
	t_node	*smallest;

	node = stack->head;
	smallest = NULL;
	while (node)
	{
		if (node->index == -1)
		{
			if (!smallest || node->value < smallest->value)
				smallest = node;
		}
		node = node->next;
	}
	return (smallest);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*node;
	int		index;

	index = 0;
	node = find_smallest_unindexed(stack);
	while (node)
	{
		node->index = index;
		index++;
		node = find_smallest_unindexed(stack);
	}
}

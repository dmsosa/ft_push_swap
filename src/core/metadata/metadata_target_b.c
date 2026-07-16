/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_target_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:49:15 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 15:09:34 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_smallest_bigger(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*best;

	node = stack->head;
	best = NULL;
	while (node)
	{
		if (node->value > value)
		{
			if (!best || node->value < best->value)
				best = node;
		}
		node = node->next;
	}
	return (best);
}

static t_node	*find_min_value(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	if (!stack->head)
		return (NULL);
	min = stack->head;
	node = min->next;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

void	update_targets_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = b->head;
	while (node)
	{
		node->target = find_smallest_bigger(a, node->value);
		if (!node->target)
			node->target = find_min_value(a);
		node = node->next;
	}
}

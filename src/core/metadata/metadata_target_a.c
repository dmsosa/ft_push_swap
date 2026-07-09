/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_target_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:49:15 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/06 16:08:05 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_biggest_smaller(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*best;

	node = stack->head;
	best = NULL;
	while (node)
	{
		if (node->value < value)
		{
			if (!best || node->value > best->value)
				best = node;
		}
		node = node->next;
	}
	return (best);
}

static t_node	*find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	if (!stack->head)
		return (NULL);
	max = stack->head;
	node = max->next;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

/*
When ordering from biggest to smallest, target needs to be
next lowest number of to_push.
this can also be called (update_targets_descending);
*/
void	update_targets_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		node->target = find_biggest_smaller(b, node->value);
		if (!node->target)
			node->target = find_max(b);
		node = node->next;
	}
}

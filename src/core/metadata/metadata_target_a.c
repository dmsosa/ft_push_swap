/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_target_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:49:15 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/17 15:02:12 by durisosa         ###   ########.fr       */
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

static t_node	*find_max_value(t_stack *stack)
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

void	update_targets_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		node->target = find_biggest_smaller(b, node->value);
		if (!node->target)
			node->target = find_max_value(b);
		node = node->next;
	}
}

/**
 * Propuesta Durian
 * No es suficiente con encontrar biggest smaller,
 * in order to corretly find the correct position
 * Is necessary to check also that the number to push
 * satisfies the following condition: 
 * a->head->value > b->head->value && 
 * a->head->value < b->tail->value
 * 
 * OR
 * 
 * a->head->value > b->head->value && 
 * a->head->value < b->next->value (in this case return pos + 1);
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:46:08 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 20:46:40 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	if (!stack || !stack->head)
		return (NULL);
	max = stack->head;
	node = max->next;
	while (node)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
	}
	return (max);
}

int	find_max_pos(t_stack *stack)
{
	t_node	*node;
	int		max_index;
	int		max_pos;
	int		pos;

	if (!stack || stack->size == 0)
		return (-1);
	node = stack->head;
	max_index = node->index;
	max_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	if (!stack || !stack->head)
		return (NULL);
	min = stack->head;
	node = min->next;
	while (node)
	{
		if (node->index < min->index)
			min = node;
		node = node->next;
	}
	return (min);
}

static void	move_min_to_top(t_stack *a)
{
	t_node	*min;
	int		rotations;

	update_positions(a);
	min = find_min(a);
	rotations = min->position;
	if (rotations <= (a->size - 1) / 2)
		while (rotations--)
			ft_ra(a);
	else
	{
		rotations = a->size - rotations;
		while (rotations--)
			ft_rra(a);
	}
}

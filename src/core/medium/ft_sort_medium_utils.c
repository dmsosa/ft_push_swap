/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/07/17 13:32:35 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_has_range(t_stack *stack, int start, int end)
{
	t_node	*node;

	if (!stack || stack->size == 0 || start > end)
		return (0);
	node = stack->head;
	while (node)
	{
		if (node->index >= start && node->index < end)
			return (1);
		node = node->next;
	}
	return (0);
}

int	next_chunk_pos(t_stack *stack, int pivot, int chunk)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->index < pivot + chunk)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
}

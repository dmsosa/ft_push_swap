/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/07/16 18:16:45 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_has_index_in_range(t_stack *stack, int start, int end)
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

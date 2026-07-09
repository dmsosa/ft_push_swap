/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:14:30 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/09 14:45:56 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		position;

	node = stack->head;
	position = 0;
	while (node)
	{
		node->above_median = (position < stack->size / 2);
		if (node->above_median)
			node->position = position;
		else
			node->position = stack->size - node->position;
		position++;
		node = node->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:14:30 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/16 14:51:53 by durisosa         ###   ########.fr       */
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
		node->position = position;
		node->above_median = (position <= (stack->size) / 2);
		position++;
		node = node->next;
	}
}

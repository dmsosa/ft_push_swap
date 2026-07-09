/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:14:30 by emmmilla          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/03 23:59:05 by emmmilla         ###   ########.fr       */
=======
/*   Updated: 2026/07/02 19:07:13 by emmmilla         ###   ########.fr       */
>>>>>>> 5f78a79 (sep repo)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		position;

	node = stack->top;
	position = 0;
	while (node)
	{
		node->position = position;
<<<<<<< HEAD
		node->above_median = (position <= (stack->size - 1) / 2);
=======
		node->above_median = (position < stack->size / 2);
>>>>>>> 5f78a79 (sep repo)
		position++;
		node = node->next;
	}
}

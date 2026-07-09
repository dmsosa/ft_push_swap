/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:32:43 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 20:00:50 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift all elements down by one position
//last becomes the first
void	ft_reverse(t_stack *stack)
{
	t_node	*new_last;
	t_node	*last;

	if (!stack || stack->size <= 1)
		return ;
	new_last = stack->head;
	while (new_last->next != stack->tail)
		new_last = new_last->next;
	last = stack->tail;
	stack->tail = new_last;
	new_last->next = NULL;
	last->next = stack->head;
	stack->head = last;
}

void	ft_rra(t_stack *a)
{
	if (!a || a->size <= 1)
		return ;
	ft_reverse(a);
	a->ops[OP_RRA]++;
	a->ops[OP_TOTAL]++;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	if (!b || b->size <= 1)
		return ;
	ft_reverse(b);
	b->ops[OP_RRB]++;
	b->ops[OP_TOTAL]++;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	b->ops[OP_RRR]++;
	b->ops[OP_TOTAL]++;
	write(1, "rrr\n", 4);
}

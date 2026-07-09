/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:32:43 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:17:10 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size <= 1)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void	ft_sa(t_stack *a)
{
	ft_swap(a);
	a->ops[OP_SA]++;
	a->ops[OP_TOTAL]++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
	b->ops[OP_SB]++;
	b->ops[OP_TOTAL]++;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	a->ops[OP_SS]++;
	a->ops[OP_TOTAL]++;
	write(1, "ss\n", 3);
}

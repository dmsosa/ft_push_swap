/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:32:48 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 20:00:56 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift everything 1 position to the top
//first becomes the last
void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	b->ops[OP_RB]++;
	b->ops[OP_TOTAL]++;
	write(1, "rb\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	a->ops[OP_RA]++;
	a->ops[OP_TOTAL]++;
	write(1, "ra\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_rr(t_stack *a, t_stack	*b)
{
	ft_rotate(a);
	ft_rotate(b);
	b->ops[OP_RR]++;
	b->ops[OP_TOTAL]++;
	write(1, "rr\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_rotate(t_stack	*stack)
{
	t_node	*old_head;
	t_node	*new_head;

	if (!stack || stack->size <= 1)
		return ;
	old_head = stack->head;
	new_head = old_head->next;
	new_head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = stack->tail;
	stack->tail->next = old_head;
	stack->tail = old_head;
	stack->head = new_head;
}

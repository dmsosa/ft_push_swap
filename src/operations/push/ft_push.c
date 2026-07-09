/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:18:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 20:00:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(a, b);
	a->ops[OP_PA]++;
	a->ops[OP_TOTAL]++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(b, a);
	b->ops[OP_PB]++;
	b->ops[OP_TOTAL]++;
	write(1, "pb\n", 3);
}

/*
push first node from src to be the new b's first node.
src's second node becomes the new a's first node.
*/
void	ft_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || !dst || src->size == 0)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	tmp->next = dst->head;
	tmp->prev = NULL;
	dst->head = tmp;
	if (dst->size == 0)
		dst->tail = tmp;
	dst->size++;
	src->size--;
}

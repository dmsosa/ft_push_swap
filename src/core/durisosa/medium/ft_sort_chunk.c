/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:56:19 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/22 21:41:42 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_index_range(t_stack *stack, int start, int end)
{
	t_node	*node;

	if (!stack || stack->size == 0 || start > end)
		return (0);
	node = stack->head;
	while (node)
	{
		if (node->index >= start && node->index <= end)
			return (1);
		node = node->next;
	}
	return (0);
}

static void	ft_chunktoa(t_stack *stack_a, t_stack *stack_b)
{
	int	last_idx_a;

	last_idx_a = 0;
	while (stack_b->size > 0)
	{
		if (stack_find_index(stack_b, stack_b->size - 1) < stack_b->size / 2)
		{
			while (stack_b->head->index != stack_b->size - 1)
				ft_rb(stack_b);
		}
		else
		{
			while (stack_b->head->index != stack_a->head->index - 1)
				ft_rrb(stack_b);
		}
		ft_pa(stack_a, stack_b);
	}
}

static void	ft_chunktob(t_stack *stack_a, t_stack *stack_b,
	int pivot, int chunk)
{
	while (stack_a->size > 3)
	{
		if (stack_a->head->index < pivot + chunk)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		if (stack_b->head != NULL && stack_b->head->index
			<= pivot + chunk / 2 && stack_b->head->index >= pivot)
			ft_rb(stack_b);
	}
}

void	ft_sort_chunk(t_stack *a, t_stack *b)
{
	int	chunk;
	int	pivot;
	int	root;

	pivot = 0;
	while (a->size > 3)
	{
		root = int_sqrt(a->size) + 1;
		if (chunk < 15)
			chunk = a->size - root;
		else
			chunk = root;
		ft_chunktob(a, b, pivot, chunk);
		pivot += chunk;
	}
	ft_sort_three(a);
	ft_chunktoa(a, b);
}

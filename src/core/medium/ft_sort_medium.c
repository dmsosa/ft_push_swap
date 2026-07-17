/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:50:20 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 18:03:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_chunktoa(t_stack *a, t_stack *b)
{
	int	max_index_a;

	stack_index_to_top(b, b->size - 1, 'b');
	ft_pa(a, b);
	stack_index_to_top(b, b->size - 1, 'b');
	ft_pa(a, b);
	max_index_a = b->size - 2;
	while (b->size > 0)
	{
		ft_pa(a, b);
		if (a->head->index < b->size - 2)
		{
			if (stack_find_index(b, b->size - 1) <= (b->size / 2))
				ft_rb(b);
			else
				ft_rr(a, b);
		}
	}
	if (a->tail->index != max_index_a && b->head->index < a->tail->index)
		rotate_index_top(b, b->size - 1, 'b');

}

static void	ft_chunktob(t_stack *a, t_stack *b, int pivot, int chunk)
{
	int	next;

	if (a->head->index < pivot + chunk)
	{
		ft_pb(a, b);
		if (b->head->value <= (pivot + (chunk / 2)))
		{
			next = next_chunk_pos(a, pivot, chunk);
			if (next <= (a->size / 2))
				ft_rr(a, b);
			else
				ft_rb(b);
		}
	}
	else
	{
		next = next_chunk_pos(a, pivot, chunk);
		rotate_pos_top(a, next, 'a');
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b)
{
	int		pivot;
	int		chunk;
	int		total_size;

	pivot = 0;
	total_size = a->size;
	chunk = int_sqrt(total_size) + 1;
	while (a->size > 0)
	{
		while (stack_has_range(a, pivot, pivot + chunk))
			ft_chunktob(a, b, pivot, pivot + chunk);
		if (pivot + chunk > total_size)
			chunk = total_size - pivot;
		pivot += chunk;

	ft_chunktoa(a, b);
}

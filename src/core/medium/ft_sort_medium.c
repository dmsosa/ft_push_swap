/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:50:20 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/15 14:53:04 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		the next chunk to push back needs tohave a distance 
//like > a.index but < a.index + chunk, 
//if it is larger than that thn he second half is beneath 
//so I do rrb

static void	ft_chunks_to_a(t_stack *a, t_stack *b, int chunk)
{
	while (b->head->index != a->head->index - 1)
	{
		if (!(b->head->index > a->head->index
				&& b->head->index < a->head->index + chunk))
			ft_rrb(b);
		else
			ft_rb(b);
	}
	ft_pa(a, b);
}

static void	ft_chunks_to_b(t_stack *a, t_stack *b, int pivot, int chunk)
{
	t_node	*tmp_a;
	int		pos_top;
	int		pos_bot;

	while (b->size < pivot + chunk && a->size > 0)
	{
		tmp_a = a->head;
		pos_top = 0;
		pos_bot = 0;
		while (tmp_a && !(tmp_a->index < pivot + chunk))
		{
			pos_top++;
			tmp_a = tmp_a->next;
		}
		tmp_a = a->tail;
		while (tmp_a && !(tmp_a->index < pivot + chunk))
		{
			pos_bot++;
			tmp_a = tmp_a->prev;
		}
		if (a->head->index < pivot + chunk)
			ft_pb(a, b);
		else
			ft_ra(a);
		if (b->size > 1 && b->head->index <= pivot + (chunk / 2))
			ft_rb(b);
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b)
{
	int	pivot;
	int	chunk;
	int	total_size;

	total_size = a->size;
	pivot = 0;
	chunk = int_sqrt(a->size) + 1;
	while (a->size > 0)
	{
		ft_chunks_to_b(a, b, pivot, chunk);
		if (pivot + chunk > total_size)
			chunk = total_size - pivot;
		pivot += chunk;
	}
	while (b->size > 0)
	{
		ft_pa(a, b);
	}
}

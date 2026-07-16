/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:50:20 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/16 20:18:29 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		the next chunk to push back needs tohave a distance 
//like > a.index but < a.index + chunk, 
//if it is larger than that thn he second half is beneath 
//so I do rrb
//max number has the max index

static void	ft_chunktoa(t_stack *a, t_stack *b)
{
	if (b->head->index != b->size - 1 && find_max_pos(b) > 2)
		return ;
	ft_pa(a, b);
}

/**
 * Calculates if the next node within range (pivot - chunk)
 * is in the first half of stack (if pos <= stack->size / 2)
 */
static int	next_is_top(t_stack *stack, int pivot, int chunk)
{
	t_node	*tmp;
	int		pos;

	if (!stack)
		return (0);
	tmp = stack->head;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < pivot + chunk)
			return (pos <= (stack->size / 2));
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_chunktob(t_stack *a, t_stack *b, int pivot, int chunk)
{
	int	count;

	while (stack_has_index_in_range(a, pivot, pivot + chunk) && a->size > 5)
	{
		if (a->head->index < pivot + chunk)
		{
			ft_pb(a, b);
			if (b->size > 0 && b->head->index <= (pivot + (chunk / 2)))
			{
				if (b->size < pivot + chunk
					&& next_is_top(a, pivot, chunk) == 1)
					ft_rr(a, b);
				else
					ft_rb(b);
			}
		}
		else if (next_is_top(a, pivot, chunk))
			ft_ra(a);
		else
			ft_rra(a);
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
		ft_chunktob(a, b, pivot, chunk);
		if (pivot + chunk > total_size)
			chunk = total_size - pivot;
		pivot += chunk;
	}
	while (b->size > 0)
		ft_chunktoa(a, b);
}

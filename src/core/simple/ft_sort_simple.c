/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:37:10 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/17 13:19:45 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotation(t_stack *a)
{
	t_node	*min;

	min = find_min(a);
	if (min)
		bring_to_top(a, min, 'a');
}

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	while (a->size > 3)
	{
		update_metadata_a_to_b(a, b);
		move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (b->size)
	{
		update_metadata_b_to_a(a, b);
		move_b_to_a(a, b);
	}
	final_rotation(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:55:03 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/17 14:44:32 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *stack, t_node *top_node)
{
	while (stack->head != top_node)
	{
		if (stack->name == 'b')
			ft_ra(stack);
		else
			ft_rb(stack);
	}
}

void	reverse_rotate_to_top(t_stack *stack, t_node *top_node)
{
	while (stack->head != top_node)
	{
		if (stack->name == 'a')
			ft_rra(stack);
		else
			ft_rrb(stack);
	}
}

void	rotate_both(t_stack *a, t_stack *b,
	t_node *top_a, t_node *top_b)
{
	while (a->head != top_a && b->head != top_b)
		ft_rr(a, b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b,
	t_node *top_a, t_node *top_b)
{
	while (a->head != top_a && b->head != top_b)
		ft_rrr(a, b);
}

void	final_rotation(t_stack *a)
{
	t_node	*min;

	min = find_min(a);
	if (min)
		bring_to_top(a, min);
}

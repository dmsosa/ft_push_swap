/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:55:03 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 20:48:30 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *stack, t_node *top_node, char name)
{
	while (stack->head != top_node)
	{
		if (name == 'b')
			ft_ra(stack);
		else
			ft_rb(stack);
	}
}

void	reverse_rotate_to_top(t_stack *stack, t_node *top_node, char name)
{
	while (stack->head != top_node)
	{
		if (name == 'a')
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

void	rotate_pos_top(t_stack *stack, int pos, char name)
{
	if (!stack || pos < 0 || pos >= stack->size)
		return ;
	if (pos <= stack->size / 2)
	{
		while (pos)
		{
			if (name == 'a')
				ft_ra(stack);
			else
				ft_rb(stack);
			pos--;
		}
	}
	else
	{
		while (pos < stack->size)
		{
			if (name == 'a')
				ft_rra(stack);
			else
				ft_rrb(stack);
			pos++;
		}
	}
}

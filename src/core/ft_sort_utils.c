/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:11:14 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:14:54 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

/*
finds the maximum node->index within the given stack.

by: durisosa
*/
int	ft_max_index(t_stack *stack)
{
	t_node	*head;
	int		max;

	head = stack->head;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

/*
finds the minimum node->index within the given stack.

by: durisosa
*/
int	ft_min_index(t_stack *stack)
{
	t_node	*head;
	int		min;

	head = stack->head;
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}

void	rotate_to_top(t_stack *stack, t_node *target, char name)
{
	int	pos;
	int	moves;
	int	reverse;

	while (stack->head != target)
	{
		if (name == 'a')
		{
			if (target->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (name == 'b')
		{
			if (target->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
		moves--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:11:14 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/15 15:12:17 by durisosa         ###   ########.fr       */
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

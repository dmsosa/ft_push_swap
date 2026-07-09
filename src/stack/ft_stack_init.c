/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:36:34 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:59:49 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->index = -1;
	return (node);
}

t_stack	*ft_stack_new(int create_ops)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (free(stack), NULL);
	stack->strategy_arg = STRAT_ADAPTIVE;
	stack->strategy_used = STRAT_ADAPTIVE;
	stack->head = NULL;
	stack->tail = NULL;
	stack->ops = NULL;
	if (create_ops)
	{
		stack->ops = ft_calloc(12, sizeof(int));
		if (!stack->ops)
			return (free(stack), NULL);
	}
	return (stack);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (!stack)
		return ;
	node = stack->head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	if (stack->ops)
	{
		free(stack->ops);
		stack->ops = NULL;
	}
	free(stack);
}

void	ft_stack_init_numbers(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	if (!a)
		return ;
	while (i < size)
	{
		ft_stackadd_back(a, ft_node_new(numbers[i]));
		i++;
	}
}

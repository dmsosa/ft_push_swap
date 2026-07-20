/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:46:24 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/20 15:41:41 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	bits;

	max_index = stack->size - 1;
	bits = 1;
	while (max_index > 1)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		ft_pa(a, b);
}

static void	process_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;

	size = a->size;
	while (size > 0)
	{
		if (((a->head->index >> bit) & 1) == 0)
			ft_pb(a, b);
		else
			ft_ra(a);
		size--;
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit);
		push_back_to_a(a, b);
		bit++;
	}
}

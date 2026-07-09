/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:59:42 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_stack **a, t_stack **b)
{
	*b = ft_stack_new(0);
	(*b)->ops = (*a)->ops;
	(*b)->bench = (*a)->bench;
	if ((*a)->size <= 5)
		ft_sort_units(*a, *b);
	else if ((*a)->strategy_used == STRAT_SIMPLE)
		ft_sort_simple(*a, *b);
	else if ((*a)->strategy_used == STRAT_MEDIUM)
		ft_sort_medium(*a, *b);
	else
		ft_sort_simple(*a, *b);
}

static t_strategy	ft_adaptive_choice(t_stack *a)
{
	a->disorder = ft_compute_disorder(a);
	if (a->disorder < 0.2)
		return (STRAT_SIMPLE);
	if (a->disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	(*a)->strategy_used = (*a)->strategy_arg;
	if ((*a)->strategy_used == STRAT_ADAPTIVE)
		(*a)->strategy_used = ft_adaptive_choice(*a);
	run_strategy(a, b);
}

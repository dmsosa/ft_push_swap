/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:40:49 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/14 21:39:16 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **argv_split, t_stack *a, t_stack *b)
{
	ft_free_split(argv_split);
	ft_free_stack(a);
	b->ops = NULL;
	ft_free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**argv_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	argv_split = split_arguments(argc, argv);
	if (!ft_valid_args(argv_split))
		return (ft_free_split(argv_split), ft_exit_error(1), 1);
	if (!ft_parse_pushswap(&a, &b, argv_split))
		return (free_all(argv_split, a, b), ft_exit_error(1), 1);
	if (!ft_stacksorted(a))
		ft_sort_strategy(&a, &b);
	if (a && a->bench)
		ft_print_bench(a);
	return (free_all(argv_split, a, b), 0);
}

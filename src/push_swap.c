/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:40:49 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 12:53:08 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*argv_str;
	char		**argv_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	argv_str = ft_strjoin_args(argc, argv);
	if (!argv_str)
		ft_exit_error(1);
	argv_split = ft_split(argv_str, ' ');
	if (!argv_split)
		return (free(argv_str), ft_exit_error(1));
	if (!ft_valid_args(argv_split))
		return (free(argv_str), ft_free_split(argv_split), ft_exit_error(1));
	if (!ft_parse_pushswap(&a, argv_split))
		return (free(argv_str), ft_free_split(argv_split), ft_exit_error(1));
	if (!ft_stacksorted(a))
		ft_sort_strategy(&a, &b);
	if (a && a->bench != NULL)
		ft_print_bench(a);
	return (free(argv_str), ft_free_split(argv_split),
		ft_free_stack(a), ft_free_stack(b), 0);
}

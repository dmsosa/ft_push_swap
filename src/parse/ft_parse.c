/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:29:35 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 14:17:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 


/*
This function is called after checking any invalid argument. 
It finds the flags that the user passes as arguments,
adaptive in case that no flag is found
bench mode if necessary

Put integers inside the stack until the first Non-integer value
if finds something Non-integer two things may happen: 
1. If it is a valid argument, stop without error
2. If it is not a valid argument, stop with error 
(but you are not supposed to have reached this point 
if that is the case)

it checks duplicated values inside the stack,
finally it initializes other stack info like strategy to be used,
complexity name,
and calculates disorder, which is going to be used by the
ft_sort function.
*/
int	ft_parse_pushswap(t_stack **a, t_stack **b, char **split)
{
	*a = ft_stack_new('a', NULL);
	if (!*a)
		return (0);
	*b = ft_stack_new('b', (*a)->ops);
	if (!*b)
		return (0);
	if (!ft_parse_flags(*a, split))
		return (0);
	if (!ft_parse_integers(*a, split))
		return (0);
	assign_indexes(*a);
	return (1);
}

char	**split_arguments(int argc, char **argv)
{
	char	*argv_str;
	char	**argv_split;

	argv_str = ft_strjoin_args(argc, argv);
	if (!argv_str)
		ft_exit_error(1);
	argv_split = ft_split(argv_str, ' ');
	free(argv_str);
	if (!argv_split)
		return (ft_exit_error(1), NULL);
	return (argv_split);
}

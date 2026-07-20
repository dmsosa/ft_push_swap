/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:28:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 14:38:47 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function iterates over the command line arguments and
activate the flags that are found
errors like more than one flag or invalid flags are already checked
returns error if an invalid input is found, ignore numbers
*/
static int	startswith_dashdash(const char *s)
{
	if (!s)
		return (0);
	return (s[0] == '-' && s[1] == '-');
}

int	ft_parse_flags(t_stack *a, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (startswith_dashdash(split[i]) && !ft_setflag_ps(a, split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_setflag_ps(t_stack *a, char *str)
{
	if (!a || !str)
		return (0);
	if (ft_strcmp("--adaptive", str) == 0)
		a->strategy_arg = STRAT_ADAPTIVE;
	else if (ft_strcmp("--simple", str) == 0)
		a->strategy_arg = STRAT_SIMPLE;
	else if (ft_strcmp("--medium", str) == 0)
		a->strategy_arg = STRAT_MEDIUM;
	else if (ft_strcmp("--complex", str) == 0)
		a->strategy_arg = STRAT_COMPLEX;
	else if (ft_strcmp("--bench", str) == 0)
		a->bench = 1;
	else
		return (0);
	return (1);
}

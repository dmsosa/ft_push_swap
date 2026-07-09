/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:19:24 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:18:00 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_isflag_ps(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp("--simple", str) == 0)
		return (1);
	else if (ft_strcmp("--medium", str) == 0)
		return (1);
	else if (ft_strcmp("--complex", str) == 0)
		return (1);
	else if (ft_strcmp("--adaptative", str) == 0)
		return (1);
	else if (ft_strcmp("--bench", str) == 0)
		return (1);
	else
		return (0);
}

int	ft_valid_istr(char *istr)
{
	int	i;

	i = 0;
	if (istr[i] == '-' || istr[i] == '+')
		i++;
	if (!istr[i] || !istr)
		return (0);
	while (istr[i])
	{
		if (!ft_isdigit(istr[i]))
			return (0);
		i++;
	}
	return (1);
}

double	ft_compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || stack->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->head;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

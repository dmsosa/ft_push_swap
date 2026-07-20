/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:59:26 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 14:51:19 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_istrs(char **split);
static int	ft_numbers_append(int *numbers, int size, int *index, char *str);

static int	ft_duplicated(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_numbers_append(int *numbers, int size, int *index, char *str)
{
	long	value;

	value = ft_atol(str);
	if (!(value >= INT_MIN && value <= INT_MAX))
		return (0);
	numbers[*index] = value;
	*index = *index + 1;
	return (1);
}

static int	ft_count_istrs(char **split)
{
	int		stop;
	int		i;
	int		count;

	i = 0;
	count = 0;
	stop = 0;
	while (split[i] && !ft_valid_istr(split[i]))
		i++;
	while (split[i] && !stop)
	{
		if (!ft_valid_istr(split[i]))
			stop = 1;
		else
			count++;
		i++;
	}
	return (count);
}

/*
creates an array of integers using an array of chars
ignores flags. Stops when find somethind that is not a number.

any invalid input was previously checked, so this function
assumes no invalid flags are present.
it fails if finds an invalid integer.
For example "--a" "+ maria", etc.

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo
*/
int	ft_parse_integers(t_stack *a, char **split)
{
	int		*numbers;
	int		size;
	int		i;
	int		j;
	int		stop;

	numbers = NULL;
	size = ft_count_istrs(split);
	numbers = malloc(size * sizeof(int));
	if (!numbers)
		return (0);
	i = 0;
	j = 0;
	while (split[i] && !ft_valid_istr(split[i]))
		i++;
	while (split[i] && ft_valid_istr(split[i]))
	{
		if (!ft_numbers_append(numbers, size, &j, split[i]))
			return (free(numbers), 0);
		i++;
	}
	if (ft_duplicated(numbers, size))
		return (free(numbers), 0);
	ft_stack_add_numbers(a, numbers, size);
	return (free(numbers), 1);
}

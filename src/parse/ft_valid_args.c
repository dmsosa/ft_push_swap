/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:58:55 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 20:00:36 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
HUGE RESPONSIBILITY ON THIS FUNCTION
Validate that we have received a valid input from the user.
Scenarios to contemplate:
./push_swap.out " 35 46 7   " 9 8 7 --simple
./push_swap.out 34 45  "" 9 8 7 " " "   " --> parse integers only until 45.
./push_swap.out 34 45  " 99 hola 3" 9 --> parse integers only until 99.
./push_swap.out "" "  " " 35 46 7  --complex " 9 8 7 

Example invalid inputs:

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo

For each argv, split it in case it is a quoted string, iterate
over the split to check if an invalid input is found.

by: durisosa
*/
char	*ft_strjoin_args(int argc, char **argv)
{
	int		i;
	char	*joined;

	i = 1;
	joined = NULL;
	while (i < argc)
	{
		joined = ft_strjoin_sep(joined, argv[i]);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}

char	*ft_strjoin_sep(char *prev, char *new)
{
	char	*joined;
	size_t	prev_len;
	size_t	new_len;

	if (!new)
		return (prev);
	if (!prev)
		prev_len = 0;
	else
		prev_len = ft_strlen(prev);
	new_len = ft_strlen(new);
	joined = malloc((prev_len + new_len + 2) * sizeof(char));
	if (!joined)
		return (free(prev), prev = NULL, NULL);
	ft_strlcpy(joined, prev, prev_len);
	ft_strlcpy(joined + prev_len, " ", 2);
	ft_strlcpy(joined + prev_len + 1, new, new_len);
	return (free(prev), joined);
}

static int	startswith_dashdash(const char *s)
{
	if (!s)
		return (0);
	return (s[0] == '-' && s[1] == '-');
}

int	ft_valid_args(char **argv_split)
{
	int		strategy_count;
	int		i;

	strategy_count = 0;
	i = 0;
	while (argv_split[i])
	{
		if (startswith_dashdash(argv_split[i]))
		{
			if (!ft_isflag_ps(argv_split[i]))
				return (0);
			else if (ft_strcmp(argv_split[i], "--bench") != 0)
				strategy_count++;
		}
		else if (!ft_valid_istr(argv_split[i]))
			return (0);
		if (strategy_count > 1)
			return (0);
		i++;
	}
	return (1);
}

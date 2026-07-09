/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:41:33 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 15:18:00 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_split_substr(const char *s, unsigned int start,
	unsigned int len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

static char	**ft_execute_split(char **split, const char *s, char c)
{
	int	k;
	int	i;
	int	j;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			split[k] = ft_split_substr(s, i, j);
			if (!split[k])
				return (NULL);
			k++;
			i += j;
		}
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_execute_split(split, s, c);
	if (!split)
		return (ft_free_split(split));
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:41:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/01 12:50:34 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
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

int	main(void)
{
	char	*str;

	/* Test 1: prev == NULL */
	str = NULL;
	str = ft_strjoin_sep(str, "42");
	printf("Result 1: \"%s\"\n", str);

	/* Test 2: append another string */
	str = ft_strjoin_sep(str, "Madrid");
	printf("Result 2: \"%s\"\n", str);

	/* Test 3: append another string */
	str = ft_strjoin_sep(str, "Push_Swap");
	printf("Result 3: \"%s\"\n", str);

	/* Test 4: new == NULL */
	str = ft_strjoin_sep(str, NULL);
	printf("Result 4: \"%s\"\n", str);

	return (0);
}

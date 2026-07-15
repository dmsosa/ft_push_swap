/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:30:03 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/14 18:56:42 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_chr(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	ft_clean_buf(char *buf)
{
	int	i;
	int	k;

	i = ft_strlen_chr(buf, '\n');
	if (buf[i])
		i++;
	k = 0;
	while (buf[i])
	{
		buf[k] = buf[i];
		i++;
		k++;
	}
	while (k < BUFFER_SIZE)
		buf[k++] = 0;
}

void	ft_strcpy_gnl(char	*dst, char	*src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin_gnl(char *prev, char *new)
{
	char	*joined;
	int		l1;
	int		l2;

	l1 = ft_strlen_chr(prev, '\0');
	l2 = ft_strlen_chr(new, '\n');
	if (new[l2])
		l2++;
	joined = malloc((l1 + l2 + 1) * sizeof(char));
	if (!joined)
		return (free(prev), NULL);
	ft_strcpy_gnl(joined, prev);
	ft_strcpy_gnl(joined + l1, new);
	if (prev)
		free(prev);
	return (joined);
}

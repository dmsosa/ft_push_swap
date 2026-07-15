/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:30:03 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/14 18:56:36 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			r;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	r = 1;
	if (!buf[0])
		r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		line = ft_strjoin_gnl(line, buf);
		ft_clean_buf(buf);
		if (!line)
			return (NULL);
		if (line[ft_strlen_chr(line, '\n')])
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (r < 0)
		return (free(line), NULL);
	return (line);
}

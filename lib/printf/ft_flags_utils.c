/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/16 20:23:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_valid_flag(char c)
{
	return (ft_isflag(c) || ft_isdigit((int) c) || ft_isspec(c));
}

int	ft_isspec(char c)
{
	if (c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'c' || c == 's'
		|| c == 'p' || c == '%' || c == 't')
		return (1);
	return (0);
}

int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == ' '
		|| c == '#' || c == '.' || c == '0')
		return (1);
	return (0);
}

void	ft_flags_width(const char **format, t_flags *flags)
{
	while (**format && ft_isdigit(**format) && !flags->asterisk)
	{
		flags->min_width = (flags->min_width * 10) + (**format - 48);
		(*format) = *format + 1;
	}
}

t_flags	*ft_flags_asterisk(t_flags *flags, t_context *ctx)
{
	flags->asterisk = 1;
	flags->min_width = va_arg(ctx->va, int);
	if (flags->min_width < 0)
	{
		flags->left = 1;
		flags->min_width *= -1;
	}
	return (flags);
}

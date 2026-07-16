/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/16 20:17:35 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printstr(char *str, t_context *ctx)
{
	int	i;

	if (!str)
	{
		if (write(ctx->fd, NULL_PTR, 6) == -1)
		{
			ctx->written = -1;
			return ;
		}
	}
	i = 0;
	while (str[i])
	{
		ft_printc(str[i], ctx);
		if (ctx->written == -1)
			return ;
		i++;
	}
}

static void	ft_printstr_precision(char *s, int precision, t_context *ctx)
{
	int	i;

	if (precision < 0)
	{
		ft_printstr(s, ctx);
		return ;
	}
	i = 0;
	while (s[i] && i < precision)
	{
		ft_printc(s[i], ctx);
		if (ctx->written == -1)
			return ;
		i++;
	}
}

static void	ft_printstr_flags_helper(char *sdup, t_flags *flags, t_context *ctx)
{
	if (flags->precision >= 0 && (size_t) flags->precision > flags->strlen)
		flags->precision = flags->strlen;
	if (flags->left)
		ft_printstr_precision(sdup, flags->precision, ctx);
	if (flags->precision >= 0)
		ft_print_pad(flags->min_width, flags->precision, 0, ctx);
	else
		ft_print_pad(flags->min_width, flags->strlen, 0, ctx);
	if (!flags->left)
		ft_printstr_precision(sdup, flags->precision, ctx);
	return ;
}

int	ft_printstr_flags(char *str, t_flags *flags, t_context *ctx)
{
	char	*sdup;

	if (!str)
		sdup = ft_strdup("(null)");
	else
		sdup = ft_strdup(str);
	if (!sdup)
		return (0);
	flags->strlen = ft_strlen(sdup);
	if (!str && (flags->precision >= 0
			&& (size_t) flags->precision < flags->strlen))
	{
		ft_print_pad(flags->min_width, 0, 0, ctx);
		return (free(sdup), 0);
	}
	ft_printstr_flags_helper(sdup, flags, ctx);
	return (free(sdup), 0);
}

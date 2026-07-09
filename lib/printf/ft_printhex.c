/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:54:19 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printhex_prefix(int to_upper, t_context *ctx)
{
	if (!to_upper)
		ft_printstr("0x", ctx);
	else
		ft_printstr("0X", ctx);
}

static void	ft_printhex_nstr(char *nstr, int n, t_flags *flags, t_context *ctx)
{
	if (!flags->zero && flags->alt && n != 0)
		ft_printhex_prefix(flags->to_upper, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	ft_print_pad(flags->precision, flags->strlen, 1, ctx);
	ft_printstr(nstr, ctx);
}

static void	ft_printhex_flags(char *nstr, unsigned int n,
		t_flags *flags, t_context *ctx)
{
	if (flags->zero && flags->alt && n != 0)
		ft_printhex_prefix(flags->to_upper, ctx);
	if (flags->left)
		ft_printhex_nstr(nstr, n, flags, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	if (flags->precision >= 0)
		ft_print_pad(flags->min_width, flags->precision + (flags->alt * 2),
			flags->zero, ctx);
	else
		ft_print_pad(flags->min_width, flags->strlen + (flags->alt * 2),
			flags->zero, ctx);
	if (!flags->left)
		ft_printhex_nstr(nstr, n, flags, ctx);
	return ;
}

int	ft_printhex(unsigned int n, int to_upper,
		t_flags *flags, t_context *ctx)
{
	char	*nstr;

	nstr = ft_print_xtoa(n, to_upper);
	if (!nstr)
		return (0);
	flags->strlen = ft_strlen(nstr);
	flags->to_upper = to_upper;
	if (flags->precision == 0 && n == 0)
	{
		ft_print_pad(flags->min_width, flags->precision, 0, ctx);
		return (free(nstr), 0);
	}
	ft_printhex_flags(nstr, n, flags, ctx);
	return (free(nstr), 0);
}

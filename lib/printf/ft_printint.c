/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:28:37 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:09 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printint_sign(int n, t_flags *flags, t_context *ctx)
{
	if (n < 0)
		ft_printc('-', ctx);
	else if (flags->sign)
		ft_printc('+', ctx);
	else if (flags->blank)
		ft_printc(' ', ctx);
	return ;
}

static void	ft_printint_nstr(char *nstr, int n, t_flags *flags, t_context *ctx)
{
	if ((!flags->zero || flags->left))
		ft_printint_sign(n, flags, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	ft_print_pad(flags->precision, flags->strlen, 1, ctx);
	if (ctx->written == -1)
		return ;
	ft_printstr(nstr, ctx);
	return ;
}

static void	ft_printint_flags(char *nstr, int n, t_flags *flags, t_context *ctx)
{
	if (flags->zero)
		ft_printint_sign(n, flags, ctx);
	if (flags->left)
		ft_printint_nstr(nstr, n, flags, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	if (n < 0 || flags->blank || flags->sign)
		flags->min_width--;
	if (flags->precision >= 0)
		ft_print_pad(flags->min_width, flags->precision, flags->zero, ctx);
	else
		ft_print_pad(flags->min_width, flags->strlen, flags->zero, ctx);
	if (!flags->left)
		ft_printint_nstr(nstr, n, flags, ctx);
	return ;
}

int	ft_printint(int n, t_flags *flags, t_context *ctx)
{
	char	*nstr;

	nstr = ft_print_itoa_abs(n);
	if (!nstr)
		return (0);
	flags->strlen = ft_strlen(nstr);
	if (flags->precision == 0 && n == 0)
	{
		ft_print_pad(flags->min_width, flags->precision, 0, ctx);
		return (free(nstr), 0);
	}
	ft_printint_flags(nstr, n, flags, ctx);
	return (free(nstr), 0);
}

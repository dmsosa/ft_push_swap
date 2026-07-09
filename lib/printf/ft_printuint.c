/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:56:09 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printuint_nstr(char *nstr, t_flags *flags,
		t_context *ctx)
{
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	if (flags->precision != -1)
	{
		ft_print_pad(flags->precision, flags->strlen, 1, ctx);
	}
	ft_printstr(nstr, ctx);
}

static void	ft_printuint_flags(char *nstr,
		t_flags *flags, t_context *ctx)
{
	if (flags->left)
		ft_printuint_nstr(nstr, flags, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	if (flags->precision >= 0)
		ft_print_pad(flags->min_width, flags->precision, flags->zero, ctx);
	else
		ft_print_pad(flags->min_width, flags->strlen, flags->zero, ctx);
	if (!flags->left)
		ft_printuint_nstr(nstr, flags, ctx);
	return ;
}

int	ft_printuint(unsigned int n, t_flags *flags, t_context *ctx)
{
	char	*nstr;

	nstr = ft_print_utoa(n);
	if (!nstr)
		return (0);
	flags->strlen = ft_strlen(nstr);
	if (flags->precision == 0 && n == 0)
	{
		ft_print_pad(flags->min_width, flags->precision, 0, ctx);
		return (free(nstr), 0);
	}
	ft_printuint_flags(nstr, flags, ctx);
	return (free(nstr), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printptr_prefix(void *ptr, t_flags *flags, t_context *ctx)
{
	if (!ptr)
		return ;
	if (flags->to_upper)
		ft_printstr("0X", ctx);
	else
		ft_printstr("0x", ctx);
}

static void	ft_printptr_string(char *pstr, void *ptr,
	t_flags *flags, t_context *ctx)
{
	if ((flags->left || !flags->zero) && ptr != 0)
		ft_printptr_prefix(ptr, flags, ctx);
	if (flags->precision >= 0)
		ft_print_pad(flags->precision, flags->strlen, 1, ctx);
	ft_printstr(pstr, ctx);
}

static void	ft_printptr_flags(char *pstr, void *ptr,
	t_flags *flags, t_context *ctx)
{
	if (flags->zero)
		ft_printptr_prefix(ptr, flags, ctx);
	if (flags->left)
		ft_printptr_string(pstr, ptr, flags, ctx);
	if (flags->precision >= 0 && (size_t) flags->precision < flags->strlen)
		flags->precision = flags->strlen;
	if (flags->precision >= 0)
		ft_print_pad(flags->min_width, flags->precision, flags->zero, ctx);
	else
		ft_print_pad(flags->min_width, flags->strlen, flags->zero, ctx);
	if (!flags->left)
		ft_printptr_string(pstr, ptr, flags, ctx);
}

int	ft_printptr(void *ptr, t_flags *flags, t_context *ctx)
{
	char	*pstr;

	if (!ptr)
		pstr = ft_strdup("(nil)");
	else
		pstr = ft_print_xtoa((unsigned long long) ptr, 0);
	if (!pstr)
		return (0);
	flags->strlen = ft_strlen(pstr);
	if (ptr != NULL)
	{
		flags->strlen += 2;
		flags->precision += 2;
	}
	ft_printptr_flags(pstr, ptr, flags, ctx);
	return (free(pstr), 0);
}

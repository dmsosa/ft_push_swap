/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:20 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flags	*ft_flags_setleft(t_flags *flags)
{
	flags->zero = 0;
	flags->left = 1;
	return (flags);
}

t_flags	*ft_flags_setsign(t_flags *flags)
{
	flags->blank = 0;
	flags->sign = 1;
	return (flags);
}

void	ft_flags_setprecision(const char **format, t_flags *flags,
	t_context *ctx)
{
	(*format) += 1;
	if (**format == '*')
	{
		flags->asterisk = 1;
		flags->precision = va_arg(ctx->va, int);
		(*format) += 1;
		return ;
	}
	flags->precision = 0;
	while (**format && ft_isdigit(**format))
	{
		flags->precision = (flags->precision * 10) + (**format - 48);
		(*format) += 1;
	}
	if (flags->zero)
		flags->zero = 0;
}

void	ft_print_pad(int width, int len, int zeroes, t_context *ctx)
{
	while (width - len > 0)
	{
		if (zeroes)
			ft_printc('0', ctx);
		else
			ft_printc(' ', ctx);
		width--;
	}
	return ;
}

t_flags	*ft_flags_init(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->valid_spec = 0;
	flags->min_width = 0;
	flags->left = 0;
	flags->zero = 0;
	flags->asterisk = 0;
	flags->precision = -1;
	flags->alt = 0;
	flags->blank = 0;
	flags->sign = 0;
	flags->to_upper = 0;
	flags->strlen = 0;
	return (flags);
}

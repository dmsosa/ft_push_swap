/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:54:24 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:19 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printc(int c, t_context *ctx)
{
	if (write(1, (char *) &c, 1) == -1)
		ctx->written = -1;
	if (ctx->written != -1)
		ctx->written += 1;
}

void	ft_printc_flags(int c, t_flags *flags, t_context *ctx)
{
	if (flags->left)
		ft_printc(c, ctx);
	if (flags->precision == 0 && c == 0)
		ft_print_pad(flags->min_width, flags->precision, 0, ctx);
	else
		ft_print_pad(flags->min_width, 1, flags->zero, ctx);
	if (!flags->left)
		ft_printc(c, ctx);
	return ;
}

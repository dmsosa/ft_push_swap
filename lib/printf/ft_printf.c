/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/16 20:20:14 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	change_fd(int fd, t_context *ctx)
{
	ctx->fd = fd;
}

static void	ft_types(char c, t_flags *flags, t_context *ctx)
{
	if (c == 'c')
		ft_printc_flags(va_arg(ctx->va, int), flags, ctx);
	else if (c == 's')
		ft_printstr_flags(va_arg(ctx->va, char *), flags, ctx);
	else if (c == 'd' || c == 'i')
		ft_printint(va_arg(ctx->va, int), flags, ctx);
	else if (c == 'p')
		ft_printptr(va_arg(ctx->va, void *), flags, ctx);
	else if (c == 'u')
		ft_printuint(va_arg(ctx->va, unsigned int), flags, ctx);
	else if (c == 'x')
		ft_printhex(va_arg(ctx->va, unsigned int), 0, flags, ctx);
	else if (c == 'X')
		ft_printhex(va_arg(ctx->va, unsigned int), 1, flags, ctx);
	else if (c == '%')
		ft_printc(c, ctx);
	else if (c == 't')
		change_fd(va_arg(ctx->va, int), ctx);
}

static t_flags	*ft_parse_flags(const char **format, t_flags *flags,
		t_context *ctx)
{
	++(*format);
	while (**format && (flags->valid_spec == 0) && ft_valid_flag(**format))
	{
		if (**format == '0' && flags->min_width == 0 && !flags->left)
			flags->zero = 1;
		if (ft_isdigit(**format))
			ft_flags_width(format, flags);
		if (**format == '.')
			ft_flags_setprecision(format, flags, ctx);
		if (**format == '-')
			flags = ft_flags_setleft(flags);
		if (**format == ' ' && !flags->sign)
			flags->blank = 1;
		if (**format == '+')
			flags = ft_flags_setsign(flags);
		if (**format == '*')
			flags = ft_flags_asterisk(flags, ctx);
		if (**format == '#')
			flags->alt = 1;
		if (ft_isspec(**format))
			return (flags->valid_spec = 1, flags);
		++(*format);
	}
	return (flags);
}

static int	ft_process_format(const char *format, t_context *ctx)
{
	t_flags	*flags;

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (-1);
			flags = ft_flags_init();
			if (!flags)
				return (free(ctx), -1);
			flags = ft_parse_flags(&format, flags, ctx);
			if (flags->valid_spec)
				ft_types(*format, flags, ctx);
			else
				ft_printc(*format, ctx);
			free(flags);
		}
		else
			ft_printc(*format, ctx);
		format++;
	}
	return (ctx->written);
}

int	ft_printf(const char	*format, ...)
{
	t_context	*ctx;
	int			done;

	if (!format || *format == '\0')
		return (-1);
	ctx = malloc(sizeof(t_context));
	if (!ctx)
		return (-1);
	va_start(ctx->va, format);
	ctx->written = 0;
	ctx->fd = 1;
	ctx->written = ft_process_format(format, ctx);
	va_end(ctx->va);
	done = ctx->written;
	return (free(ctx), done);
}

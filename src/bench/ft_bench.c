/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:02 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:59:12 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_bench(t_stack *a)
{
	if (!a)
		return ;
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(a->ops[OP_TOTAL], 2);
	ft_putchar_fd('\n', 2);
}

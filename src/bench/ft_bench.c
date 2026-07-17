/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:02 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 13:14:08 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_op(t_stack *a, int op, int fd)
{
	if (op == OP_PA)
		return (ft_putstr_fd("pa: ", fd), ft_putnbr_fd(a->ops[OP_PA], fd));
	else if (op == OP_PB)
		return (ft_putstr_fd("pb: ", fd), ft_putnbr_fd(a->ops[OP_PB], fd));
	else if (op == OP_SA)
		return (ft_putstr_fd("sa: ", fd), ft_putnbr_fd(a->ops[OP_SA], fd));
	else if (op == OP_SB)
		return (ft_putstr_fd("sb: ", fd), ft_putnbr_fd(a->ops[OP_SB], fd));
	else if (op == OP_SS)
		return (ft_putstr_fd("ss: ", fd), ft_putnbr_fd(a->ops[OP_SS], fd));
	else if (op == OP_RA)
		return (ft_putstr_fd("ra: ", fd), ft_putnbr_fd(a->ops[OP_RA], fd));
	else if (op == OP_RB)
		return (ft_putstr_fd("rb: ", fd), ft_putnbr_fd(a->ops[OP_RB], fd));
	else if (op == OP_RR)
		return (ft_putstr_fd("rr: ", fd), ft_putnbr_fd(a->ops[OP_RR], fd));
	else if (op == OP_RRA)
		return (ft_putstr_fd("rra: ", fd), ft_putnbr_fd(a->ops[OP_RRA], fd));
	else if (op == OP_RRB)
		return (ft_putstr_fd("rrb: ", fd), ft_putnbr_fd(a->ops[OP_RRB], fd));
	else if (op == OP_RRR)
		return (ft_putstr_fd("rrr: ", fd), ft_putnbr_fd(a->ops[OP_RRR], fd));
}

static void	ft_print_op_while(t_stack *a, int begin_op, int end_op, int fd)
{
	int	i;

	i = begin_op;
	while (i <= end_op)
	{
		ft_print_op(a, i, fd);
		if (i < end_op)
			ft_putchar_fd(' ', fd);
		i++;
	}
}

static void	ft_print_disorder(double disorder, int fd)
{
	int	disorder_int;

	disorder_int = (int)(disorder * 100 + 0.5);
	if (disorder_int >= 100)
		ft_putstr_fd("100.00%", fd);
	else
	{
		ft_putnbr_fd(disorder_int, fd);
		ft_putstr_fd(".00%", fd);
	}
}

static void	ft_print_strategy(t_stack *a, int fd)
{
	if (a->strategy_arg == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptive / ", fd);
	else if (a->strategy_arg == STRAT_SIMPLE)
		ft_putstr_fd("Simple (Insertion Sort) / ", fd);
	else if (a->strategy_arg == STRAT_MEDIUM)
		ft_putstr_fd("Medium (Chunk Sort)/ ", fd);
	else if (a->strategy_arg == STRAT_COMPLEX)
		ft_putstr_fd("Complex (Radix Sort) / ", fd);
	if (a->strategy_used == STRAT_SIMPLE)
		ft_putstr_fd("O(n²)", fd);
	else if (a->strategy_used == STRAT_MEDIUM)
		ft_putstr_fd("O(n√n)", fd);
	else if (a->strategy_used == STRAT_COMPLEX)
		ft_putstr_fd("O(n log n)", fd);
}

void	ft_print_bench(t_stack *a)
{
	if (!a)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_print_disorder(a->disorder, 2);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_print_strategy(a, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(a->ops[OP_TOTAL], 2);
	ft_putstr_fd("\n[bench] ", 2);
	ft_print_op_while(a, OP_SA, OP_PB, 2);
	ft_putstr_fd("\n[bench] ", 2);
	ft_print_op_while(a, OP_RA, OP_RRR, 2);
	ft_putchar_fd('\n', 2);
}

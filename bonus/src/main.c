/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:22:10 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/15 21:42:46 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_do_op(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(a, b);
	else
		return (0);
	return (1);
}

static void	free_all(char **argv_split, t_stack *a, t_stack *b)
{
	ft_free_split(argv_split);
	ft_free_stack(a);
	b->ops = NULL;
	ft_free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**argv_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	argv_split = split_arguments(argc, argv);
	if (!ft_valid_args(argv_split))
		return (free(argv_split), ft_exit_error(1), 1);
	if (!ft_parse_pushswap(&a, &b, argv_split))
		return (free_all(argv_split, a, b), ft_exit_error(1), 1);
	ft_read_instructions(a, b);
	if (ft_stacksorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

void	ft_read_instructions(t_stack *a, t_stack *b)
{
	int		op_count;
	char	*line;

	op_count = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!ft_do_op(line, a, b))
			exit_error();
		free(line);
		op_count++;
		if (op_count == a->ops[OP_TOTAL])
			break ;
		line = get_next_line(0);
	}
}

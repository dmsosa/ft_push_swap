/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:42:53 by handler           #+#    #+#             */
/*   Updated: 2026/07/14 20:01:26 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	do_op(char *str, t_stack *a, t_stack *b);
void	exit_error(void);
void	ft_read_instructions(t_stack *a, t_stack *b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:34:36 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/01 13:39:21 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exit_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
	return (1);
}

int	ft_return_error(int print)
{
	if (print)
		ft_putstr_fd("Error\n", 2);
	return (1);
}


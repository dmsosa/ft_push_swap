/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/09 19:59:05 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdisorder_fd(double disorder, int fd)
{
	int	disorder_100;

	disorder_100 = (int)(disorder * 100 + 0.5);
	if (disorder_100 >= 100)
	{
		ft_putstr_fd("100.00%", fd);
		return ;
	}
	ft_putnbr_fd(disorder_100, fd);
	ft_putstr_fd(".00%", fd);
}

void	ft_pulabel_fd(const char *label, int number, int fd)
{
	ft_putstr_fd((char *)label, fd);
	ft_putnbr_fd(number, fd);
}

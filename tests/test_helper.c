/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:41:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 16:16:04 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(void)
{
	t_stack	*stack;
	char	*arr1;

	arr1 = ft_strdup("23 45 6 7 11 9 1");
	ft_parse_pushswap(ft_count_words(arr1), arr1);
	stack = ft_parse_stack(ft_count_words(arr1), arr1);
	ft_printstack(stack);
	return (0);
}

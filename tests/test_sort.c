/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:41:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 16:16:13 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(void)
{
	char	*str;
	char	*se1;
	char	*se2;
	char	*se3;
	char	*se4;
	int		arr[] = {3, 2, 1, 5, 97, 43, 6, 7, 42, 8};

	se1 = ft_strdup("--simple");
	se2 = ft_strdup("--medium");
	se3 = ft_strdup("--complex");
	se4 = ft_strdup("--adaptive");

	printf("Hello World %.2f\n",
		ft_compute_disorder(arr, (sizeof(arr) / sizeof(int))));
	printf("Hello World %d\n", strcmp(str, se1));
	return (0);
}

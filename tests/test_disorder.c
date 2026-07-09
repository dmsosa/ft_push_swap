/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_disorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:41:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 16:15:58 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// float	ft_compute_disorder(int *numbers, int size)
// {
// 	int	mistakes;
// 	int	total_pairs;
// 	int	i;
// 	int	j;

// 	i = -1;
// 	mistakes = 0;
// 	total_pairs = 0;
// 	while (++i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (numbers[i] > numbers[j])
// 				mistakes++;
// 			total_pairs++;
// 			j++;
// 		}
// 	}
// }

// float stack_compute_disorder(t_stack *stack)
// {
//     int mistakes;
//     int total_pairs;
//     int i;
//     int j;
//     int size;

//     size = ft_stacksize(stack);
//     i = -1;
//     mistakes = 0;
//     total_pairs = 0;
//     while (++i < size)
//     {
//         j = i + 1;
//         while (j < size)
//         {
//             if (stack->value > (stack->next)->value)
//                 mistakes++;
//             total_pairs++;
//             j++;
//         }
//     }
// }
int	main(void)
{
	int	arr[] = {59, 89, 7, 29, 1, 90, 3};

	printf("Hello World %f", ft_compute_disorder(arr, 7));
	return 0;
}

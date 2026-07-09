/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:15 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_digits_hex(unsigned long long n, int base)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 1;
	while (n / base != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ft_print_xtoa(unsigned long long n, int to_upper)
{
	size_t	len;
	char	*nstr;
	int		mod;

	len = ft_count_digits_hex(n, 16);
	nstr = malloc((len + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[len--] = '\0';
	while (len != (size_t)-1)
	{
		mod = n % 16;
		if (mod < 10)
			nstr[len] = mod + '0';
		else
		{
			if (to_upper)
				nstr[len] = (mod - 10) + 'A';
			else
				nstr[len] = (mod - 10) + 'a';
		}
		len--;
		n /= 16;
	}
	return (nstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/23 13:44:16 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_digits(long long n, int base)
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

static int	ft_count_digits_ul(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_print_itoa_abs(int n)
{
	long	nl;
	size_t	len;
	char	*nstr;

	nl = (long) n;
	len = ft_count_digits(nl, 10);
	nstr = malloc((len + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[len--] = '\0';
	if (nl < 0)
		nl = -nl;
	while (len > 0)
	{
		nstr[len] = (nl % 10) + '0';
		len--;
		nl /= 10;
	}
	nstr[len] = (nl % 10) + '0';
	return (nstr);
}

char	*ft_print_utoa(unsigned int n)
{
	char	*nstr;
	size_t	len;

	len = ft_count_digits_ul(n);
	nstr = malloc((len + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[len--] = '\0';
	while (len)
	{
		nstr[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	nstr[len] = (n % 10) + 48;
	return (nstr);
}

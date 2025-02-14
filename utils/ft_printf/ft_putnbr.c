/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:39:56 by bozil             #+#    #+#             */
/*   Updated: 2024/11/23 12:01:18 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		c += 1;
		n = -n;
	}
	if (n >= 10)
		c += ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	c += 1;
	return (c);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	c;

	c = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 10)
		c += ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	c += 1;
	return (c);
}

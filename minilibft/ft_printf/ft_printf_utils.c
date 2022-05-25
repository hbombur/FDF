/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:01:25 by hbombur           #+#    #+#             */
/*   Updated: 2022/01/12 21:23:48 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	result;

	if (!s)
		return (write(1, "(null)", 6));
	result = 0;
	while (*s)
	{
		write(1, s++, 1);
		result++;
	}
	return (result);	
}

int	ft_putnbr_base(unsigned long long n, int i, char *str)
{
	if (n < (unsigned long long) i)
		return (write(1, str + n, 1));
	return (ft_putnbr_base((n / i), i, str) + ft_putnbr_base((n % i), i, str));	
}

int	ft_putnbr(int n)
{
	if (n < 0)
		return ((write(1, "-", 1) + ft_putnbr_base(((unsigned int) (n * -1)), 10, "0123456789")));
	return (ft_putnbr_base(n, 10, "0123456789"));
}

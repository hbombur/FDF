/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:06:08 by hbombur           #+#    #+#             */
/*   Updated: 2022/01/12 21:23:49 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_flags(const char *str, int i, va_list ap)
{
	int	result;

	if (str[i] == 'c')
		result = ft_putchar(va_arg(ap, int));
	else if (str[i] == 's')
		result = ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'p')
		result = (write(1, "0x", 2) + ft_putnbr_base((va_arg(ap, unsigned long)), 16, "0123456789abcdef"));
	else if (str[i] == 'd')
		result = ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'i')
		result = ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		result = ft_putnbr_base((va_arg(ap, unsigned int)), 10, "0123456789");
	else if (str[i] == 'x')
		result = ft_putnbr_base((va_arg(ap, unsigned int)), 16, "0123456789abcdef");
	else if (str[i] == 'X')
		result = ft_putnbr_base((va_arg(ap, unsigned int)), 16, "0123456789ABCDEF");
	else if (str[i] == '%')
		result = write(1, "%", 1);
	else
		return (0);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_printf_flags(str, ++i, ap);
			i++;
		}
		else
		{
			write(1, &str[i++], 1);
			result++;
		}
	}
	va_end(ap);
	return (result);
}

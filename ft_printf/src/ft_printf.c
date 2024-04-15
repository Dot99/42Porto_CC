/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:39 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/15 12:50:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_check(char c, va_list ptr)
{
	int	result;

	result = 0;
	if(!c)
		return (0);
	if (c == 'c')
		result += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		result += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		result += ft_putptr(va_arg(ptr, unsigned long));
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		result += ft_utoa(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_putnbrhex(va_arg(ptr, int), c);
	else if (c == '%')
		result +=  write(1, "%", 1);
	return (result);
		
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int	result;

	va_start(ptr, str);
	result = 0;
	if(!str)
		return (0);
	while (*str != 0)
	{
		if(*str == '%')
			result += ft_check(*(++str), ptr);
		else 
			result += write(1, str, 1);
		++str;
	}

	va_end(ptr);
	return (result);
}
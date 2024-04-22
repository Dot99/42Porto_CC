/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:41 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/22 12:24:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *nbr)
{
	int		result;
	unsigned long	n;

	n = (unsigned long)nbr;
	result = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return(6);
	}
	result += ft_printstr("0x");
	if (n == 0)
		result += ft_putchar(0);
	else
		result += ft_putnbrhex(n, 'x');
	return (result);
}
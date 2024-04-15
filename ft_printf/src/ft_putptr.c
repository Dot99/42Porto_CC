/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:41 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/15 12:16:51 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(unsigned long nbr)
{
	int		result;

	result = 0;
	if (!nbr)
	{
		write(1, "(null)", 6);
		return(6);
	}
		
	result += ft_putstr("0x");
	result += ft_putnbrhex(nbr, 'x');
	return (result);
}
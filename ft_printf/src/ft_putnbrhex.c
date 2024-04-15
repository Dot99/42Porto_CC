/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:18:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/15 11:44:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbrhex(unsigned int nb, const char c)
{
	unsigned int	nbr;
	char	*base;
	
	nbr = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDF";
	if(nb >= 16)
	{
		nbr += ft_putnbrhex((nbr / 16), c);
		nbr += ft_putnbrhex((nbr & 16), c);
	}
	else
	{
		nbr += write(1, &base[nbr], 1);
	}
	
	return(nbr);
}
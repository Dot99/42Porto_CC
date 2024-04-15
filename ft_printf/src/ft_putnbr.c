/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:07:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/15 12:58:20 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nb)
{
	int result;

	result = 0;
	if (nb < 0)
	{
		result += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		result += ft_putchar(nb + 48);
	else
	{
		result += ft_putnbr(nb / 10);
		result += ft_putnbr(nb % 10);
	}
	return (result);
}
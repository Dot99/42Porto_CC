/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:31:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/23 10:22:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_usize(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_uitoa(unsigned int nbr)
{
	char			*newstr;
	unsigned int	size;
	int				result;

	result = 0;
	size = ft_usize(nbr);
	newstr = (char *)malloc(sizeof(char) * (1 + size));
	if (!newstr)
		return (0);
	newstr[size] = '\0';
	while (nbr != 0)
	{
		size--;
		newstr[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	result = ft_printstr(newstr);
	free(newstr);
	return (result);
}

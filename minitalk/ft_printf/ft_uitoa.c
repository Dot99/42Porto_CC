/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:31:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/29 11:14:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file ft_uitoa.c
 * @brief Convert a unsigned into to a ascii string
*/

#include "ft_printf.h"

/**
 * @brief Get Length of number
 * 
 * @param nbr Number
 * @return unsigned int Length
*/
unsigned int	ft_usize(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

/**
 * @brief Convert the unsigned int to ascii and print it
 * 
 * @param nbr Number
 * @return int Length of number converted to string
*/
int	ft_uitoa(unsigned int nbr)
{
	char			*newstr;
	size_t			size;
	int				result;

	result = 0;
	size = ft_usize(nbr);
	newstr = (char *)malloc(sizeof(char) * (1 + size));
	if (!newstr)
		return (0);
	newstr[size] = '\0';
	if (nbr == 0)
		newstr[0] = '0';
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

/**@}*/
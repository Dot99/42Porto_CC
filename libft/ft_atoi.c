/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:05:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 09:40:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file ft_atoi.c
 * @brief Ascii to Int
*/

#include "libft.h"

/**
 * @brief Converts a string with numbers to its equivalent in INT
 * 
 * @param str String with numbers to convert
 * @return int Converted string of numbers
 */
int	ft_atoi(const char *str)
{
	int	number;
	int	i;
	int	negative;

	i = 0;
	negative = 1;
	number = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	if ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			negative *= -1;
		i++;
	}
	if ((str[i] == 43) || (str[i] == 45))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * negative);
}

/**@}*/
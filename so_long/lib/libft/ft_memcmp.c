/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:13 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 11:03:05 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file ft_memcmp.c
 * @brief Compares memories
*/

#include "libft.h"

/**
 * @brief Compares the memory space of s1 and s2
 * 
 * @param s1 Pointer to memory
 * @param s2 Pointer to memory
 * @param n Number of bytes
 * @return int Difference between both s1 and s2
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n)
		while (n--)
			if (*str1++ != *str2++)
				return (*(--str1) - *(--str2));
	return (0);
}

/**@}*/
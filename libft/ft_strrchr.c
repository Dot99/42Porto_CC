/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:18:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/09 15:46:33 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;

	chr = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			chr = (char *)s;
			break;
		}
		s++;
	}
	return (chr);
}

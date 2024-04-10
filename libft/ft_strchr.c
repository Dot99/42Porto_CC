/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:36 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/09 14:56:33 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*chr;
	int		i;

	i = -1;
	chr = (char *)s;
	while (chr[++i] != c)
	{
		if (!chr[i])
			return (NULL);
	}
	return (chr[i]);
}

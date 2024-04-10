/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:18:19 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/09 16:00:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *origin,const char *find, int n)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	if (!find[i])
		return (origin);
	while ((origin[i] && origin[i] != find[i]) && (i < n))
		i++;
	if (i > n)
		return (0);
	k = i;
	while (find[j])
	{
		if (k > n)
			return (0);
		if (origin[k] == find[j++])
			k++;
		else
			return (0);
	}
	return (origin + i);
}

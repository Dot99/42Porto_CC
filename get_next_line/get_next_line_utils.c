/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:59:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:54 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] && str[i] != c))
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;
	int	size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strclen(str, '\0');
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (c == '\0')
		return (str + i);
	if (size <= i)
		return (NULL);
	return (str + i);
}
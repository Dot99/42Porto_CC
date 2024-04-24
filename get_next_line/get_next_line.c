/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:59:37 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/24 12:47:49 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	
	if(fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = read_file(fd, stash);
}

char	*read_file(int fd, char stash)
{
	char	*size;
	int		*buffer;

	size = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	*buffer = 0;
	while (size && ft_strchr(buffer, '\n'))
	{
		
	}
}

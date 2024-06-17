/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:39:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/17 10:21:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_map(char *file)
{
	t_mapc	*map;
	int fd;
	char *line;
	int i;
	int j;
	
	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		while (line[i])
		{
			map->value[j][i] = line[i];
			map->x[i] = i;
			i++;
		}
		map->y[j] = j;
		j++;
	}
}
///@brief Start the map
void init(char *file)
{
	int height;
	int width;
	int	fd;
	t_maps	*map;

	height = 0;
	width = 0;
	fd = open(file, O_RDONLY);
	width = ft_strlen(get_next_line(fd));
	height++;
	while(fd)
	{
		get_next_line(fd);
		height++;
	}
	map->width = width;
	map->height = height;
	fill_map(file);
}

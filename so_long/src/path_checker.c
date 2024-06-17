/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:52:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/17 10:22:16 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*start(t_maps *map, t_mapc *map_content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map_content->value[i][j] == 'P')
			{
				return (map_content->x[i], map_content->y[j]);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **value, t_maps *map, int x, int y)
{
	static int objectives;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return;
	if (value[x][y] == '1')
		return;
	if (value[x][y] = 'C')
		objectives++;
	
	flood_fill(value, map, x + 1, y);
	flood_fill(value, map, x, y + 1);
	flood_fill(value, map, x - 1, y);
	flood_fill(value, map, x, y - 1);
}
///@brief Checks if there is an avaiable path from start to collectibles to end
void	check_path(t_maps *map, t_mapc *content, t_map_components *components)
{
	int	*start_node;

	start_node = start(map, content);
	flood_fill(content->value, map, start_node[0], start_node[1]);
}

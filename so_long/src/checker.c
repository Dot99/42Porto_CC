/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:40:27 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/17 10:22:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_y(t_maps *map_size, t_mapc *map_content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_size->height)
	{
		j = 0;
		if (map_content->x[j] == 0 || map_content->x[j] == map_size->width)
		{
			while (j < map_size->width)
			{
				if (map_content->value[i][j] != '1')
					dead(5);
				j++;
			}
		}
		i++;
	}
}

void	check_x(t_maps *map_size, t_mapc *map_content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_size->width)
	{
		j = 0;
		if(map_content->y[j] == 0 || map_content->y[j] == map_size->height)
		{
			while (j < map_size->height)
			{
				if(map_content->value[i][j] != '1')
					dead(5);
				j++;
			}
		}
		i++;
	}
}

void check_content(t_maps *map_size, t_mapc *map_content, t_map_components *components)
{
	int i;
	int j;

	i = 0;
	j = 0;
	components->collectibles = 0;
	components->player = 0;
	components->exit = 0;
	while(i < map_size->width)
	{
		j = 0;
		while (j < map_size->height)
		{
			if (map_content->value[i][j] == 'P')
				components->player++;
			else if (map_content->value[i][j] == 'C')
				components->collectibles++;
			else if (map_content->value[i][j] == 'E')
				components->exit++;
			if (components->exit != 1  ||  components->player != 1 || components->collectibles == 0)
				dead(5);
		}
		i++;
	}
}
///@brief Checks the Map
void	checker(char *file, t_maps *map)
{
	t_mapc	*map_content;
	t_map_components *components;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		dead(2);
	else
	{
		if (map->width < map->height)
			dead(4);
		check_y(map, map_content);
		check_x(map, map_content);
		check_content(map, map_content, components);
		check_path(map, map_content, components);
	}
}

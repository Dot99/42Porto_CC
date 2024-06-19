/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:10:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/19 13:16:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
	{
		map[y][x] = 'F';
		game->gathered++;
	}
	if (map[y][x] == 'E' && game->gathered != game->collectibles)
	{
		map[y][x] = 'F';
		return ;
	}
	else
		map[y][x] = 'F';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y - 1);
}

void	check_valid_path(t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * game->width);
	if (!map)
		dead(6);
	while (++game->coords.y < game->height)
		map[game->coords.y] = ft_strdup(game->map[game->coords.y]);
	flood_fill(map, game, game->player.x, game->player.y);
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			if (map[game->coords.y][game->coords.x] == 'C'
				|| map[game->coords.y][game->coords.x] == 'E')
			{
				free_array(map, game->height);
				dead(3);
			}
		}
	}
	free_array(map, game->width);
}

void	check_map_assets(t_game *game)
{
	t_point	coords;

	coords.y = -1;
	while (++coords.y < game->height)
	{
		coords.x = -1;
		while (game->map[coords.y][++coords.x] != '\0')
		{
			if (game->map[coords.y][coords.x] != '0'
				&& game->map[coords.y][coords.x] != '1'
				&& game->map[coords.y][coords.x] != 'P'
				&& game->map[coords.y][coords.x] != 'E'
				&& game->map[coords.y][coords.x] != 'C'
				&& game->map[coords.y][coords.x] != '\n'
				&& game->map[coords.y][coords.x] != '\r')
			dead(7);
		}
	}
}

void	check_collectibles(t_game *game)
{
	if (game->collectibles <= 0)
		dead(7);
}
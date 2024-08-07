/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:48 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 10:35:49 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @file movement.c
 * @brief Movements and win checker
 * 
 */
#include "so_long.h"

/**
 * @brief Win Checker
 * @details Besides checking if the player has won
 * @param game Struct of the game
 */
void	check_win(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected != game->collectibles)
	{
		return ;
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected == game->collectibles)
	{
		ft_printf("You win!\n");
		ft_exit(game);
	}
}

/// @brief Movement up
/// @param game Struct of the game
void	move_up(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y - 1;
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/player.xpm",
		game->player.x * SIZE, n_pos * SIZE + ((SIZE / 3) * 2));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(5000000);
	put_tile(game, "./textures/player.xpm", game->player.x * SIZE, n_pos * SIZE
		+ ((SIZE / 3)));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/player.xpm",
		game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_win(game);
}

/// @brief Movement down
/// @param game Struct of the game
void	move_down(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y + 1;
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/player.xpm",
		game->player.x * SIZE, n_pos * SIZE - ((SIZE / 3) * 2));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/player.xpm", game->player.x * SIZE, n_pos * SIZE
		- ((SIZE / 3)));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/player.xpm",
		game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_win(game);
}

/// @brief Movement left
/// @param game Struct of the game
void	move_left(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x - 1;
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./textures/player.xpm", n_pos * SIZE + ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/player.xpm", n_pos * SIZE + ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/player.xpm",
		n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_win(game);
}

/// @brief Movement right
/// @param game Struct of the game
void	move_right(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x + 1;
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./textures/player.xpm", n_pos * SIZE - ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/player.xpm", n_pos * SIZE - ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/player.xpm",
		n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_win(game);
}

/**@}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:48:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/04 11:07:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/// @brief Render the tile to show the number of movements
/// @param game Struct of the game
void	render_moves(t_game *game)
{
	char	*moves;
	int		x;
	int		y;

	x = (game->width - 1) * SIZE;
	y = (game->height + 1) * SIZE;
	moves = ft_itoa(game->moves);
	put_tile(game, "./textures/black.xpm", x, y - 64);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xCC0000, "MOVES:");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0xCC0000, moves);
	free(moves);
}

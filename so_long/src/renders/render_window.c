/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:59:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/21 15:07:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/// @brief Renders the game
/// @param game Struct of the game
void	render_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		dead(8);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * SIZE),
			(game->height * SIZE), "so_long");
	if (game->win_ptr == NULL)
		dead(8);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->width * SIZE,
			game->height * SIZE);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

/// @brief Renders the window and map
/// @param game 
void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
	 	dead(8);
	render_map(game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &ft_exit,
		game);
	mlx_loop(game->mlx_ptr);
}
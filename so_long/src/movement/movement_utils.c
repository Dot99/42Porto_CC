/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:36:13 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/18 15:37:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_exit(game);
	if (keysym == XK_w || keysym == XK_Up)
		validate_move_up(game);
	if (keysym == XK_s || keysym == XK_Down)
		validate_move_down(game);
	if (keysym == XK_a || keysym == XK_Left)
		validate_move_left(game);
	if (keysym == XK_d || keysym == XK_Right)
		validate_move_right(game);
	return (0);
}

void	validate_move_up(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y - 1][p_pos.x] == 'E'
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y - 1][p_pos.x] == '1'))
		return ;
	else
		move_up(game);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	validate_move_down(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y + 1][p_pos.x] == 'E'
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y + 1][p_pos.x] == '1'))
		return ;
	else
		move_down(game);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	validate_move_left(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y][p_pos.x - 1] == 'E'
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y][p_pos.x - 1] == '1'))
		return ;
	else
		move_left(game);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	validate_move_right(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y][p_pos.x + 1] == 'E'
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y][p_pos.x + 1] == '1'))
		return ;
	else
		move_right(game);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}
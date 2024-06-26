/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:48:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/27 08:59:34 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Function to show errors and exit
/// @param num Num of the error
void	dead(int num)
{

	ft_printf("Error\n");
	if (num == 1)
		ft_printf("%s\n", MAP_ERROR);
	else if (num == 2)
		ft_printf("%s\n", MAP_ERROR_EX);
	else if (num == 3)
		ft_printf("%s\n", MAP_ERROR_PATH);
	else if (num == 4)
		ft_printf("%s\n", WRONG_SIZE_MAP);
	else if (num == 5)
		ft_printf("%s\n", WRONG_MAP_FORMAT);
	else if (num == 6)
		ft_printf("%s\n", WRONG_MALLOC);
	else if (num == 7)
		ft_printf("%s\n", WRONG_NUM);
	else if (num == 8)
		ft_printf("%s\n", MLX_ERROR);
	exit(EXIT_SUCCESS);
}

/// @brief Frees the map 
/// @param map The map matrix
/// @param lines The lines of the matrix
void	free_array(char **map, int lines)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free(map);
		return ;
	}
	while (++i < lines)
		free (map[i]);
	free(map);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

/// @brief Function to exit the game cleanly
/// @param game  
int	ft_exit(t_game *game)
{
	free_all(game);
	exit (EXIT_SUCCESS);
}

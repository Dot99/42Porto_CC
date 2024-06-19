/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:34:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/19 15:32:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

///@brief Libraries
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

///@brief  Error Messages
# define MAP_ERROR "Failed to open map"
# define MAP_ERROR_EX "Map extension not allowed"
# define MAP_ERROR_PATH "Map path is wrong"
# define WRONG_SIZE_MAP "Size of the map is incorrect"
# define WRONG_MAP_FORMAT "Format of map is incorrect"
# define WRONG_MALLOC "An error happened in a malloc"
# define WRONG_NUM "Number of player,exit or collectible is wrong"
# define MLX_ERROR "There has been an error on MLX"

# define SIZE 64

//------------------STRUCTS----------------------//

/// @brief Struct for coordinates of the map
typedef struct s_coord
{
	int x;
	int y;
}				t_point;

/// @brief Struct for image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/// @brief Base struct for the game
/// @param map Matrix of coords
/// @param player Coords of player
typedef struct s_game
{
	char 	**map;
	int		width;
	int		height;
	int 	collectibles;
	int		gathered;
	int		collected;
	int		moves;
	t_point	coords;
	t_point	player;
	t_point	exit;
	t_point	tile;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_game;

//-------------------FUNCTIONS-----------------//

//---------GENERAL---------//

void	dead(int num);
int		ft_exit(t_game *game);
void	free_array(char **map, int lines);
int		ft_n_strclen(const char *str);

//---------MAP STUFF---------//

t_game	*init(void);
void	check_extension(char *file);
void	read_map(char *file, t_game *game);
void	check_extension(char *file);
void	map_validation(t_game *game);
void	check_map_size(t_game *game);
void	check_borders(t_game *game);
void	check_map_content(t_game *game);
void	check_valid_path(t_game *game);
void	check_map_assets(t_game *game);
void	check_collectibles(t_game *game);
void	fill_map(int fd, t_game *game);
void	init_game(t_game *game);
void	init_img(t_game *game);

//---------Render---------//

void	render(t_game *game);
void	render_window(t_game *game);
void	render_map(t_game *game);
void	put_tile(t_game *game, char *tile, int x, int y);
void	render_corners(t_game *game, int x, int y);
void	render_borders(t_game *game, int x, int y);
void	render_tiles(t_game *game, int x, int y);

//---------MOVEMENT---------//

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		handle_keypress(int keysym, t_game *game);
void	validate_move_up(t_game *game);
void	validate_move_down(t_game *game);
void	validate_move_left(t_game *game);
void	validate_move_right(t_game *game);

#endif
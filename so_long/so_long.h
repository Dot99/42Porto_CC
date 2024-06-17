/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:34:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/17 10:22:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG.H
# define SO_LONG.H

# include "lib/libft/libft.h"

///@brief  Error Messages
#define ARG_ERROR "Num of args incorrect" //1
#define MAP_ERROR_EX "Map extension not allowed" //2
#define MAP_ERROR_PATH "Map path is wrong" //3
#define WRONG_SIZE_MAP "Size of the map is incorrect" //4
#define WRONG_MAP_FORMAT "Format of map is incorrect"//5

//------------------STRUCTS----------------------//

/** @brief Size of map
 *	@param width - Width of the map
 *	@param height - Height of the map
*/ 
typedef struct s_map_size
{
	int	width;
	int	height;
}				t_maps;

/** @brief Content of map
 *	@param x - Array of x coordinates 
 *	@param y - Array of y coordinates
 *	@param value - Double array with the value of x and y coordinate
*/
typedef struct s_map_content
{
	int *x;
	int *y;
	char **value;
}				t_mapc;

/** @brief Number of characters
 * @param player - Num of player(It has to be 1 at all times)
 * @param collectibles - Num of collectibles (Has to be at least one)
 * @param exit - Num of exit (It has to be 1 at all times)
*/
typedef struct s_map_components
{
	int player;
	int collectibles;
	int exit;
}				t_map_components;
//-------------------FUNCTIONS-----------------//

void	init(char *map);
void	checker(char *map, t_maps *map_coords);
void	check_path(map, map_content);

#endif
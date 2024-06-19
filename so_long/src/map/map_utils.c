/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:42:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/19 11:44:34 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_n_strclen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

int	count_lines(char *fileName)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(fileName, O_RDONLY);
	if (fd < 0)
		dead(1);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
}

/// @brief Reads the map
/// @param file Name of file
/// @param game Struct of the game
void	read_map(char *file, t_game *game)
{
	int	fd;

	game->height = count_lines(file);
	if (game->height <= 0)
		dead(4);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		dead(1);
	game->map = malloc(sizeof(char *) * (game->width));
	if (!game->map)
		dead(6);
	fill_map(fd, game);
	game->width = ft_n_strclen(game->map[0]);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:39 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/19 15:27:54 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game *game;

	if (argc == 2)
	{
		check_extension(argv[1]);
		game = init();
		fd = open(argv[1], O_RDONLY);
		if(fd < 0)
			dead(1);
		read_map(argv[1], game);
		map_validation(game);
		render(game);
		exit(EXIT_SUCCESS);
	}
	return(0);
}

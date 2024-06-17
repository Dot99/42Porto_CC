/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:39 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/11 08:51:49 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps *map;

	if (argc != 2)
	{
		return (dead(1), EXIT_SUCCESS);
	}
	init(argv[1]);
	checker(argv[1], map);
	//TODO: Parse Map
	//TODO: Main function
}

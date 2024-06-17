/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:48:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/07 11:22:00 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dead(int num)
{
	ft_printf("Error\n");
	if (num == 1)
		ft_printf("%s\n", ARG_ERROR);
	else if (num == 2)
		ft_printf("%s\n", MAP_ERROR_EX);
	else if (num == 3)
		ft_printf("%s\n", MAP_ERROR_PATH);
	else if (num == 4)
		ft_printf("%s\n", WRONG_SIZE_MAP);
	else if (num == 5)
		ft_printf("%s\n", WRONG_MAP_FORMAT);
	exit(EXIT_SUCCESS);
}

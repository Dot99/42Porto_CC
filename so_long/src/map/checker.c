/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:40:27 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/04 16:54:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file checker.c
 * @brief Checks the extension of the file
 */

#include "so_long.h"

/// @brief Checks extension of file
/// @param file Name of file
void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		dead(2);
}

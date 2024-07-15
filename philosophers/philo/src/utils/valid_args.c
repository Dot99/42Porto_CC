/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:23:38 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 10:32:42 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file valid_args.c
 * @brief Validate arguments
*/
#include "philo.h"

static bool	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

static bool	is_alldigits(char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6) || !is_alldigits(av))
		return (false);
	return (true);
}
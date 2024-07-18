/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:46:19 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/18 12:03:49 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_forks.c
 * @brief Initialize the forks
 */
#include "philo.h"

void	free_forks(pthread_mutex_t *forks, int end)
{
	int	i;

	i = 0;
	while (i <= end)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

pthread_mutex_t	*init_forks(t_args *args)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(args->nbr_philo * sizeof(pthread_mutex_t));
	if (!forks)
		dead(forks, args, NULL, MLC_ERROR);
	while (i < args->nbr_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			free_forks(forks, i);
			dead(forks, args, NULL, MTX_ERROR);
		}
		i++;
	}
	return (forks);
}

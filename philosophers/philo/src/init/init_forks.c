/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:46:19 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 15:02:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_forks.c
 * @brief Initialize the forks
 */
#include "philo.h"

pthread_mutex_t	*init_forks(t_args *args)
{
	pthread_mutex_t *forks;
	int				i;

	i = 0;
	forks = malloc(args->nbr_of_philo * sizeof(pthread_mutex_t));
	if (!forks)
		dead(forks, args, MLC_ERROR);
	while (i < args->nbr_of_philo)
	{
		if (pthread_mutex_init(&args->mutex, NULL) != 0)
			dead(forks, args, MTX_ERROR);
		i++;
	}
	return (forks);
}
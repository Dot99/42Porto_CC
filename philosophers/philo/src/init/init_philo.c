/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:01:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 15:10:20 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_philo.c
 * @brief Initialize the philosophers
 */
#include "philo.h"

t_philo	*init_philos(t_args *args, pthread_mutex_t *forks)
{
	t_philo	*philo;
	int		i;
	
	i = 0;
	philo = malloc(args->nbr_of_philo * sizeof(t_philo));
	if (!philo)
		dead(forks, args, MLC_ERROR);
	while (i < args->nbr_of_philo)
	{
		philo[i].nbr_philo = i + 1;
		philo[i].num_eat = 0;
		philo[i].args = args;
		i++;
	}
	return(philo);
}

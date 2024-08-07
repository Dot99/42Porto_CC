/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:01:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/18 12:04:28 by gude-jes         ###   ########.fr       */
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

	i = -1;
	philo = malloc(args->nbr_philo * sizeof(t_philo));
	if (!philo)
		dead(forks, args, philo, MLC_ERROR);
	while (++i < args->nbr_philo)
	{
		philo[i].nbr_philo = i + 1;
		philo[i].num_eat = 0;
		philo[i].l_fork = &forks[i];
		philo[i].r_fork = &forks[(i + 1) % args->nbr_philo];
		philo[i].last_meal = get_time();
		philo[i].args = args;
	}
	return (philo);
}

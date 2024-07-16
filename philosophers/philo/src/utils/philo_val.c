/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:43:36 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/16 15:28:11 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	hungry(t_philo *philo)
{
	suseconds_t current_time = get_time();
    suseconds_t time_since_last_meal = current_time - philo->last_meal;

    return (time_since_last_meal > philo->args->time_to_die * 1000);
}

bool	is_philo_dead(t_args *args, t_philo *philo, int *philo_fed)
{
	if(args->eat_times > 0 && philo->num_eat >= args->eat_times)
		(*philo_fed)++;
	if(hungry(philo))
	{
		pthread_mutex_unlock(&args->mutex);
		handler(philo, DEATH);
		pthread_mutex_lock(&args->mutex);
		args->end = true;
		pthread_mutex_unlock(&args->mutex);
		return(true);
	}
	return(false);
}

void	all_fed(t_args *args)
{
	args->end = true;
	printf("Philosophers are done eating! Each one ate %d\n", args->eat_times);
	pthread_mutex_unlock(&args->mutex);
}
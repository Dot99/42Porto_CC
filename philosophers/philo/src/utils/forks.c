/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:03:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/16 12:09:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_forks2(t_philo *philo)
{
	if (philo->nbr_philo % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		handler(philo, FORK);
		pthread_mutex_unlock(philo->r_fork);
		handler(philo, FORK);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		handler(philo, FORK);
		pthread_mutex_unlock(philo->l_fork);
		handler(philo, FORK);
	}	
}

void	handle_forks(t_philo *philo, bool handle)
{
	if (handle)
	{
		if (philo->nbr_philo % 2 == 0)
		{
			pthread_mutex_lock(philo->l_fork);
			handler(philo, FORK);
			pthread_mutex_lock(philo->r_fork);
			handler(philo, FORK);
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			handler(philo, FORK);
			pthread_mutex_lock(philo->l_fork);
			handler(philo, FORK);
		}
	}
	else
		handle_forks2(philo);
}

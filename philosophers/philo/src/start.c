/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:40:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 15:58:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

suseconds_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

bool	start(t_args *args, pthread_mutex_t *fork, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		philo[i].start = get_time();
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/18 12:02:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dead.c
 * @brief Handles errors and frees structs

 */
#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_all(pthread_mutex_t *forks, t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	if (args)
		pthread_mutex_destroy(&args->mutex);
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
	if (forks)
	{
		while (i < args->nbr_philo)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		free(forks);
		forks = NULL;
	}
}

void	dead(pthread_mutex_t *forks, t_args *args, t_philo *philo, char *error)
{
	free_all(forks, args, philo);
	write(STDERR_FILENO, "ERROR: ", 7);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

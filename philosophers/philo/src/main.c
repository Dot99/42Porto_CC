/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:04:37 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/18 11:43:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Main of the program
 */
#include "philo.h"

int	main(int ac, char **av)
{
	t_args			args;
	t_philo			*philo;
	pthread_mutex_t	*fork;

	if (!valid_args(ac, av) || !init_args(&args, av))
		dead(NULL, NULL, NULL, WRONG_ARG);
	fork = init_forks(&args);
	philo = init_philos(&args, fork);
	if (!start(&args, fork, philo))
		return (EXIT_FAILURE);
	free_all(fork, &args, philo);
	return (EXIT_SUCCESS);
}

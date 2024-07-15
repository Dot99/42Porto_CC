/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:04:37 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 15:42:25 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Main of the program
 */
#include "philo.h"

int	main(int ac, char **av)
{
	t_args			*args;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	
	if (!valid_args(ac, av) || !init_args(&args, av))
		dead(NULL, NULL, WRONG_ARG);
	fork = init_forks(&args);
	philo = init_philo(&args, fork);
	start(args, fork, philo);
	exit(EXIT_SUCCESS);
}

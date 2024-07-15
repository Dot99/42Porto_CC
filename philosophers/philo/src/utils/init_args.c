/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:32:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/15 14:56:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_args.c
 * @brief Initiate the struct args with value from argv
 */
#include "philo.h"

int ft_atoi(char *str)
{
	int sign;
	int result;
	int i;

	sign = 1;
	result = 0;
	i = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == 43 || str[i] == 45)
	{
		if(str[i] == 45)
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return(result * sign);
}
/**
 * @brief Main function to initialize arguments
 * 
 * @param args Struct of the arguments
 * @param av Matrix of the arguments
 * @return true Arguments are correct
 * @return false Wrong Arguments
 */
bool	init_args(t_args *args, char **av)
{
	args->nbr_of_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->must_eat_times = -1;
	if(av[5])
		args->must_eat_times = ft_atoi(av[5]);
	if(args->nbr_of_philo == 0 || args->must_eat_times == 0)
	{
		dead(NULL, args, WRONG_ARG);
		return(false);
	}
	if(pthread_mutex_init(&args->mutex, NULL) != 0)
	{
		dead(NULL, args, MTX_ERROR);
		return(false);
	}
	args->end = false;
	return(true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:49:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/16 15:30:05 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

///@brief Libraries
# include <memory.h> // memset()
# include <stdio.h> // printf()
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write(), usleep()
# include <sys/time.h> // gettimeofday()
# include <pthread.h> // POSIX thread API
# include <stdbool.h> // boolean data type

///@brief Error Messages
# define WRONG_ARG "Invalid Arguments"
# define MTX_ERROR "Mutex Error"
# define MLC_ERROR "Malloc Error"
# define THR_ERROR "Thread error"

/// @brief Philosophers Messages
# define FORK "has taken the fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEATH "died\n"

/// @brief Arguments Struct
typedef struct s_args {
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_times;
	pthread_mutex_t		mutex;
	bool				end;

}				t_args;

/// @brief Struct of philo
typedef struct s_philo {
	int					nbr_philo;
	int					num_eat;
	suseconds_t			start;
	suseconds_t			last_meal;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t			t_id;
	t_args				*args;
}			t_philo;

/// @brief Handle args
bool	valid_args(int ac, char **av);
bool	init_args(t_args *args, char **av);

/// @brief Initialization of forks and philo
pthread_mutex_t	*init_forks(t_args *args);
t_philo	*init_philos(t_args *args, pthread_mutex_t *forks);

/// @brief Starts the threads
bool	start(t_args *args, pthread_mutex_t *fork, t_philo *philo);

/// @brief Handle forks actions
void	handle_forks(t_philo *philo, bool handle);

/// @brief Event Handler
void	handler(t_philo *philo, char *event);

/// @brief  Checks if the philosopher is dead
bool	is_philo_dead(t_args *args, t_philo *philo, int *philo_fed);

/// @brief Checks if everyone ate 
void	all_fed(t_args *args);

/// @brief Time
suseconds_t	get_time(void);

/// @brief "Loop for threads"
void	*loop(void *_philo);

/// @brief Handles errors
void	dead(pthread_mutex_t *forks, t_args *args, char *error);

/// @brief Frees
void	free_all(pthread_mutex_t *forks, t_args *args);

#endif
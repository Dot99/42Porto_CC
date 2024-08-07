/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:32:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/04 12:10:59 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file client.c
 * @brief Client Side
*/

#include "../include/minitalk.h"

/**
 * @brief Dynamic Sleep
 * 
 * @param size Length of string
 * @return size_t Time to sleep
*/
size_t	ft_sleep(size_t size)
{
	if (size <= 10000)
		return (50);
	else if (size <= 30000)
		return (100);
	else if (size <= 60000)
		return (300);
	else if (size <= 100000)
		return (500);
	else
		return (10000);
}

/**
 * @brief Convert ascii to binary
 * 
 * @param pid Process Id
 * @param c Character to convert
 * @param size Length of string
*/
void	ft_atob(int pid, char c, size_t size)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Erro ao mandar SIGUSR1\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Erro ao mandar SIGUSR2\n");
				exit(1);
			}
		}
		usleep(ft_sleep(size));
		bit++;
	}
}

/**
 * @brief Main function of client
 * 
 * @param argc Number of arguments
 * @param argv String of arguments
 * @return int 0 if everything OK | 1 if not
*/
int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Erro\n");
			return (1);
		}
		while (i <= ft_strlen(argv[2]))
		{
			ft_atob(pid, argv[2][i], ft_strlen(argv[2]));
			i++;
		}
	}
	else
	{
		ft_printf("Erro\n");
		return (1);
	}
	return (0);
}

/**@}*/
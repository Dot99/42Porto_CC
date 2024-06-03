/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:32:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/03 12:49:21 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

size_t	ft_sleep(size_t size)
{
    if (size <= 10000)
        return(50);
    else if (size <= 30000)
        return(100);
    else if (size <= 60000)
        return(300);
    else if (size <= 100000)
        return(500);
    else
        return(10000);
}

void	ft_atob(int pid, char c, size_t size)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(ft_sleep(size));
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
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

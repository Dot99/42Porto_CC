/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:32:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/04 12:12:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @file server.c
 * @brief Server side
*/

#include "../include/minitalk.h"

/**
 * @brief Join a character to a string
 * 
 * @param s1 String to add the character
 * @param c Character to be joined
 * @return char* New string
*/
char	*ft_strcjoin(char const *s1, char c)
{
	int		size;
	int		i;
	char	*newstring;

	if (s1)
		size = ft_strlen(s1);
	else
		size = 0;
	newstring = (char *)malloc(sizeof(char) * (size + 2));
	if (!newstring)
	{
		free(newstring);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		newstring[i] = s1[i];
	newstring[i++] = c;
	newstring[i] = '\0';
	return (newstring);
}

/**
 * @brief Convert binary to ascii
 * 
 * @param sig Signal being received
*/
void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;
	static char	*str;
	char		*temp;

	if (!str)
		str = ft_calloc(1, 1);
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		temp = ft_strcjoin(str, (char)i);
		free(str);
		str = temp;
		if (i == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		bit = 0;
		i = 0;
	}
}

/**
 * @brief Main function of server
 * 
 * @param argc Number of arguments
 * @param argv String of arguments
 * @return int 0 if everything OK | 1 if not
*/
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s", "Erro\n");
		return (1);
	}
	pid = getpid();
	ft_printf("> %s\n", "Gude-jes Server");
	ft_printf("> [PID]: %d \n", pid);
	ft_printf("> %s \n", "Output:");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}

/**@}*/
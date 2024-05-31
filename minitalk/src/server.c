/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:32:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/31 12:57:39 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
		return (NULL);
	i = -1;
	while (s1[++i])
		newstring[i] = s1[i];
	newstring[i++] = c;
	newstring[i] = '\0';
	if(s1)
		free((char *)s1);
	return (newstring);
}

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;
	static char *str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return ;
		*str = '\0';
	}
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
    if (bit == 8) {
        str = ft_strcjoin(str, (char)i);
        if (i == 0) {
            ft_printf("%s\n", str);
            free(str);
            str = NULL;
        }
        bit = 0;
        i = 0;
    }
}

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

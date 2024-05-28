/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:18:07 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/28 12:30:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handle_argv(char **argv, int argc)
{
	char	**new_argv;

	new_argv = argv + 1;
	if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		if (!new_argv)
			dead(NULL, NULL);
	}
	return (new_argv);
}

int	func_num_elem(char **argv)
{
	int	num_elem;

	num_elem = 0;
	while (argv[num_elem] != NULL)
		num_elem++;
	return (num_elem);
}

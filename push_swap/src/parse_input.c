/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:38:44 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/28 12:17:06 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	has_duplicates(int *storage, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (storage[i] == storage[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	*conv_a_to_i(t_stack *a, int argc, char **argv)
{
	int		*int_list;
	int		i;
	int		j;
	ssize_t	nr;

	int_list = malloc((argc) * sizeof(int));
	i = 0;
	j = 0;
	while (argv[j])
	{
		nr = ft_atol(argv[j]);
		if (nr > INT_MAX || nr <= INT_MIN)
		{
			free(int_list);
			dead(a, NULL);
		}
		int_list[i] = (int)nr;
		i++;
		j++;
	}
	return (int_list);
}

static bool	is_alldigits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				(argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				return (false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

int	*parse_input(int argc, char **argv, t_stack *a)
{
	int	*storage;

	if (!is_alldigits(argv))
		dead(a, NULL);
	storage = conv_a_to_i(a, argc, argv);
	if (has_duplicates(storage, argc - 1))
	{
		free(storage);
		dead(a, NULL);
	}
	return (storage);
}

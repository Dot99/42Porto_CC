/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:41:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/17 08:44:38 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int *storage, int chunk_size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < chunk_size)
	{
		key = storage[i];
		j = i - 1;
		while (j >= 0 && storage[j] > key)
		{
			storage[j + 1] = storage[j];
			j -= 1;
		}
		storage[j + 1] = key;
		i += 1;
	}
}

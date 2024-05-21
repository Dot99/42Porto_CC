/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:54:28 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/20 11:28:25 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void free_data(int *count, int *output)
{
	free(count);
	free(output);
}

static void	find_min_max(int *arr, int size, int *min, int *max)
{
	int	i;

	*min = arr[0];
	*max = arr[0];
	i = 0;
	while (++i < size)
	{
		if (arr[i] < *min)
			*min = arr[i];
		if (arr[i] > *max)
			*max = arr[i];
	}
}

static void	fill_count(int *arr, int size, int *count, int min)
{
	int	i;

	i = -1;
	while (++i < size)
		count[arr[i] - min]++;
}

static void	apply_count(int *arr, int size, int *count, int *output, int min)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = output[i];
		i++;
	}
}

void	counting_sort(int *arr, int size)
{
	int i;
	int max;
	int min;
	int range;
	int *count;
	int *output;

	find_min_max(arr, size, &min, &max);
	range = max - min + 1;
	count = malloc(range * sizeof(int));
	output = malloc(size * sizeof(int));
	if (!count || !output)
		free_data(count, output);
	i = -1;
	while (++i < range)
		count[i] = 0;
	fill_count(arr, size, count, min);
	i = -1;
	while (++i < range)
	{
		count[i] += count[i - 1];
	}
	//printf("\n");
	apply_count(arr, size, count, output, min);
	free_data(count, output);
}

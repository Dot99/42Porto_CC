/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:54:28 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/28 11:50:54 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	free_data(t_count_data *data)
{
	free(data->count);
	free(data->output);
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

static void	fill_count(int *arr, int size, t_count_data *data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		data->count[arr[i] - data->min]++;
		i++;
	}
}

static void	apply_count(int *arr, int size, t_count_data *data)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		data->output[data->count[arr[i] - data->min] - 1] = arr[i];
		data->count[arr[i] - data->min]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = data->output[i];
		i++;
	}
}

void	counting_sort(int *arr, int size)
{
	int				i;
	int				max;
	int				min;
	int				range;
	t_count_data	data;

	find_min_max(arr, size, &min, &max);
	range = max - min + 1;
	data.min = min;
	data.count = malloc(range * sizeof(int));
	data.output = malloc(size * sizeof(int));
	if (!data.count || !data.output)
		free_data(&data);
	i = -1;
	while (++i < range)
		data.count[i] = 0;
	fill_count(arr, size, &data);
	i = 0;
	while (++i < range)
	{
		data.count[i] += data.count[i - 1];
	}
	apply_count(arr, size, &data);
	free_data(&data);
}

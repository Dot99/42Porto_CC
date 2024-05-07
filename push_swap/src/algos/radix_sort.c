/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:59:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/07 13:01:54 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, int size)
{
	int i;
	int key;
	int j;

	i = 0;
	while (i < size)
	{
		key = arr[i];
		j = i + 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

static int sort_arr(t_stack *stack)
{
	int *sorted_arr;
	int i;
	
	sorted_arr = malloc(stack->stack_size * sizeof(int));
	i = 0;
	while(i < stack->stack_size)
	{
		sorted_arr[i] = stack->storage[i];
		i++;
	}
	insertion_sort(sorted_arr, stack->stack_size);
	return (sorted_arr);
}

static void index(t_stack *stack, int *sort_arr)
{
	int i;
	int *temp;
	int j;
	
	i = -1;
	temp = malloc(stack->stack_size * sizeof(int));
	while (++i < stack->stack_size)
	{
		j = -1;
		while(++j < stack->stack_size)
		{
			if(sort_arr[i] == stack->storage[i])
				temp[j] = i;
		}
	}
}

void	radix(t_stack *a, t_stack *b)
{
	int max_bits;
	int	max_value;

	max_bits = 0;
	max_value = max(a);
	while(max_value >> max_bits != 0)
		max_bits++;
	index(a, sort_arr(a));
}

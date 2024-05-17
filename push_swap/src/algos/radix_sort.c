/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:59:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/17 12:00:38 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, int size)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int *sort_arr(t_stack *stack)
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

	i = -1;
	temp = malloc((max(stack) + 1) * sizeof(int));
	while (++i < stack->stack_size)
		temp[sort_arr[i]] = i;
	i = -1;
	while(++i < stack->stack_size)
		stack->storage[i] = temp[stack->storage[i]];
	free(temp);
}


void	radix_sort(t_stack *a, t_stack *b)
{
	int max_bits;
	int	value;
	int i;
	int j;

	index(a, sort_arr(a));
	max_bits = 0;
	value = max(a);
	while(value >> max_bits != 0)
		max_bits++;
	i = -1;
    while (++i < max_bits)
    {
		j = -1;
		while (++j < a->stack_size)
		{
			value = a->storage[a->top];
			if (((value >> i) & 1) == 1)
				ra(a, true);
			else
				pb(a, b, true);
		}
		while (!is_empty(b))
			pa(a, b, true);
	}
}

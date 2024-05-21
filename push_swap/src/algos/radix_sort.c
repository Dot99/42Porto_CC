/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:59:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/20 12:02:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	counting_sort(sorted_arr, stack->stack_size);
	return (sorted_arr);
}

static void index(t_stack *stack, int *sorted_arr)
{
	int i;
	int *index_map;

	index_map = malloc((max(stack) + 1) * sizeof(int));
	i = -1;
	while (++i <= max(stack))
		index_map[i] = 0;
	i = -1;
	while (++i < stack->stack_size)
		index_map[sorted_arr[i]] = i + 1;
	i = -1;
	while (++i < stack->stack_size)
		stack->storage[i] = index_map[stack->storage[i]];
	free(index_map);
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
    while (++i < max_bits && !is_sorted(a))
    {
		j = -1;
		while (++j < a->stack_size && !is_sorted(a))
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

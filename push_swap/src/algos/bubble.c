/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:53:40 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/08 12:08:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while(i < 2)
	{
		j = 0;
		while(j < 2)
		{
			if(a->storage[j] > a->storage[j + 1])
			{
				sa(a, true);
			}
			ra(a, true);
			j++;
		}
		rra(a, true);
		rra(a, true);
		i++;
	}
}
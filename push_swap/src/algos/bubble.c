/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:53:40 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/14 12:52:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_stack *a)
{
	if (a->storage[a->top] > a->storage[a->top - 1])
		sa(a, true);
	if (a->storage[a->top - 1] > a->storage[a->top - 2])
	{
		ra(a, true);
		if (a->storage[a->top] > a->storage[a->top - 1])
			sa(a, true);
		rra(a, true);
	}
	if (a->storage[a->top] > a->storage[a->top - 1])
		sa(a, true);
}

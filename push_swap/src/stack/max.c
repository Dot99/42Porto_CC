/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:47:03 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/21 09:31:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->storage[BOTTOM];
	i = BOTTOM;
	while (i < stack->top)
	{
		if (stack->storage[i] > max)
			max = stack->storage[i];
		i += 1;
	}
	return (max);
}

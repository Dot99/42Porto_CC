/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:38:48 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/20 12:41:11 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *stack)
{
	int min;
	int i;

	i = stack->top;
	min = stack->storage[stack->top];
	while (i >= 0)
	{
		if(stack->storage[i] < min)
			min = stack->storage[i];
		i--;
	}
	return(min);
}
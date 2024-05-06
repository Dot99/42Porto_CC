/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:45:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/06 11:49:04 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_sorted(t_stack *a)
{
	int	i;
	
	i =0;
	while(i < a->top)
	{
		if (a->storage[i] < a->storage[i + 1])
			return(false);
		i++;
	}
	return(true);
}
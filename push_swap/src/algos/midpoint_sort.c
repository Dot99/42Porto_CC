/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:59:20 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/08 12:08:43 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void midpoint_sort(t_stack *a, t_stack *b)
{
	int mid;

	if(is_empty(a) || a->top == 0)
		return ;
	mid = (a->top + 1) / 2;
	while(a->top >= mid)
		pb(a, b, true);
	midpoint_sort(a, b);
	midpoint_sort(b, a);
	while(!is_empty(b))
		pa(a,b, true);
}
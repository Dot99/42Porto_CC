/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:53:40 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/29 11:05:29 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->storage[a->top] > a->storage[a->top -1])
		ra(a, true);
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->storage[a->top];
	mid = a->storage[a->top -1];
	bot = a->storage[a->top -2];
	if (top > mid && mid > bot)
	{
		sa(a, true);
		rra(a, true);
	}
	else if (top > bot && bot > mid)
		ra(a, true);
	else if (mid > top && top > bot)
		rra(a, true);
	else if (mid > bot && bot > top)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (bot > top && top > mid)
		sa(a, true);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_value;

	min_value = min(a);
	while (a->storage[a->top] != min_value)
		ra(a, true);
	if (!is_sorted(a))
	{
		pb(a, b, true);
		sort_3(a);
		pa(a, b, true);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_value;

	min_value = min(a);
	while (a->storage[a->top] != min_value)
		ra(a, true);
	pb(a, b, true);
	sort_4(a, b);
	pa(a, b, true);
}

void	specific(t_stack *a, t_stack *b)
{
	if (a->stack_size == 2)
		sort_2(a);
	else if (a->stack_size == 3)
		sort_3(a);
	else if (a->stack_size == 4)
		sort_4(a, b);
	else
		sort_5(a, b);
}

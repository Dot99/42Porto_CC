/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:58:20 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/24 10:52:04 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, bool print_inst)
{
	int	tmp;
	int	i;

	if (is_empty(a))
		return ;
	tmp = a->storage[a->top];
	i = a->top;
	while (i > 0)
	{
		a->storage[i] = a->storage[i - 1];
		i--;
	}
	a->storage[BOTTOM] = tmp;
	if (print_inst)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack *b, bool print_inst)
{
	int	tmp;
	int	i;

	if (is_empty(b))
		return ;
	tmp = b->storage[b->top];
	i = b->top;
	while (i > 0)
	{
		b->storage[i] = b->storage[i - 1];
		i--;
	}
	b->storage[BOTTOM] = tmp;
	if (print_inst)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rra(t_stack *a, bool print_inst)
{
	int	tmp;
	int	i;

	if (is_empty(a))
		return ;
	tmp = a->storage[BOTTOM];
	i = 0;
	while (i < a->top)
	{
		a->storage[i] = a->storage[i + 1];
		i++;
	}
	a->storage[a->top] = tmp;
	if (print_inst)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack *b, bool print_inst)
{
	int	tmp;
	int	i;

	if (is_empty(b))
		return ;
	tmp = b->storage[BOTTOM];
	i = 0;
	while (i < b->top)
	{
		b->storage[i] = b->storage[i + 1];
		i++;
	}
	b->storage[b->top] = tmp;
	if (print_inst)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

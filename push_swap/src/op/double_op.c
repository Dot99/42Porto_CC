/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:50:08 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/07 10:56:12 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_stack *a, t_stack *b)
{
	sa(a, true);
	sb(b, true);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void rr(t_stack *a, t_stack *b)
{
	ra(a, true);
	rb(b, true);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void rrr(t_stack *a, t_stack *b)
{
	rra(a, true);
	rrb(b, true);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
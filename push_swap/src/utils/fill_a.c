/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/29 11:10:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack *a, int *int_arr, int argc)
{
	int	i;

	i = (argc - 1);
	while (i >= 0)
	{
		push(a, int_arr[i]);
		i--;
	}
	free(int_arr);
}

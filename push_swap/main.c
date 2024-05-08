/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:30:17 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/08 12:58:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = init_stack(argc - 1);
	fill_a(&a, parse_input(argc, argv, &a), argc);
	b = init_stack(argc - 1);
	if (!is_sorted(&a))
	{
		if (a.stack_size == 3)
			bubble_sort(&a);
		else if (a.stack_size >= 200)
			radix_sort(&a, &b);
		else
			midpoint_sort(&a, &b);
	}
	free_stacks(&a, &b);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:30:17 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/20 12:56:07 by gude-jes         ###   ########.fr       */
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

		if (a.stack_size <= 5)
			specific(&a, &b);
		else
			radix_sort(&a, &b);
	}
	free_stacks(&a, &b);
	return (EXIT_SUCCESS);
}

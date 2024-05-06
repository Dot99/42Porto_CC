/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:43 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/06 11:15:59 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dead(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (a)
		free(a->storage);
	if (b)
		free(b->storage);
	exit(EXIT_FAILURE);
}
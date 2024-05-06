/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/06 11:51:06 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# include "../libft/libft.h"

typedef struct s_stack {
	int	stack_size;
	int	*storage;
	int	top;
}				t_stack;

# define BOTTOM 0

// Initializes stack a
static inline t_stack	init_stack(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.storage = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

int		*parse_input(int argc, char **argv, t_stack *a);

// Fills stack a with input values
void	fill_a(t_stack *a, int *int_arr, int argc);

// Checks if stack is empty
bool	is_empty(t_stack *stack);

// Checks if stack is full
bool	is_full(t_stack *stack);

// Checks if stack is sorted
bool	is_sorted(t_stack *stack);

// Finds the max value within the stack
int		max(t_stack *stack);

// Pushes A value to the top of the stack
void	push(t_stack *stack, int value);

// Pops and returns the top element from the stack 
int		pop(t_stack *stack);

// Frees both stack storages
void	free_stacks(t_stack *a, t_stack *b);

// Frees both stack storages if they're not NULL
// prints Error to STDERR and exit on EXIT_FAILURE
void	dead(t_stack *a, t_stack *b);
#endif
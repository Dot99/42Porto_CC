/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/28 12:27:48 by gude-jes         ###   ########.fr       */
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
// STACK ---------

typedef struct s_stack
{
	int	stack_size;
	int	*storage;
	int	top;
}				t_stack;

// Counting sort struct -------
typedef struct s_count_data
{
	int	*count;
	int	*output;
	int	min;
}	t_count_data;

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

// ------------------------INSTRUCTIONS --------------------------------------
// ----------------------------SWAP ------------------------------------------

// Swaps the first 2 elements of stack a
void	sa(t_stack *a, bool print_instruction);
// Swaps the first 2 elements of stack b
void	sb(t_stack *b, bool print_instruction);
// sa + sb
void	ss(t_stack *a, t_stack *b);

//----------------------------- PUSH -----------------------------------------

// Pops the top element of stack b into stack a
void	pa(t_stack *a, t_stack *b, bool print_instruction);
// Pops the top element of stack a into stack b
void	pb(t_stack *a, t_stack *b, bool print_instruction);

//---------------------------- ROTATE ---------------------------------------

// Shifts up all elements on stack a by 1
void	ra(t_stack *a, bool print_instruction);
// Shifts up all elements on stack b by 1
void	rb(t_stack *b, bool print_instruction);
// ra + rb
void	rr(t_stack *a, t_stack *b);
// Shifts down all elements on stack a by 1
void	rra(t_stack *a, bool print_instruction);
// Shifts down all elements on stack b by 1
void	rrb(t_stack *b, bool print_instruction);
// ra + rb
void	rrr(t_stack *a, t_stack *b);

int		*parse_input(int argc, char **argv, t_stack *a);

//-------------------------- STACK UTILS ---------------------------------------
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

// Finds the min value within the stack
int		min(t_stack *stack);

// Pushes A value to the top of the stack
void	push(t_stack *stack, int value);

// Pops and returns the top element from the stack 
int		pop(t_stack *stack);

// Frees both stack storages
void	free_stacks(t_stack *a, t_stack *b);

// Frees argv
void	free_argv(char **argv);

// Frees both stack storages if they're not NULL
// prints Error to STDERR and exit on EXIT_FAILURE
void	dead(t_stack *a, t_stack *b);

// Handle argument stuff
char	**handle_argv(char **argv, int argc);
int		func_num_elem(char **argv);

//Algos
void	specific(t_stack *a, t_stack *b);
void	counting_sort(int *arr, int size);
void	radix_sort(t_stack *a, t_stack *b);
#endif
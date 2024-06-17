# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 08:45:55 by gude-jes          #+#    #+#              #
#    Updated: 2024/06/17 08:42:08 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I./includes
VPATH = src src/algos src/op\
		src/stack src/utils
LIBFT = ./libft/libft.a
RM = rm -rf

ALGOS = insertion_sort radix_sort specific
INSTRUCTIONS = double_op single_op single_op2
STACK = frees is_sorted max stack_utils min
UTILS = fill_a dead args_utils
GENERAL = parse_input

# PUSH_SWAP ---------------------------------------------
NAME = push_swap
SRCS = $(addsuffix .c, $(ALGOS))\
	   $(addsuffix .c, $(INSTRUCTIONS))\
	   $(addsuffix .c, $(STACK))\
	   $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(GENERAL))\
	   main.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.SILENT:
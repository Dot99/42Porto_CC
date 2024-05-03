# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/04/16 11:33:59 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGLIB			= -rcs
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbrhex.c ft_uitoa.c\
			ft_putptr.c ft_putchar.c ft_printf_utils.c
OBJS =  $(SRCS:.c=.o)

LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $(NAME)"
	@cp $(LIBFT) $(NAME)
	@ar $(FLAGLIB) $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
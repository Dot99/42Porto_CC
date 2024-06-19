# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 08:48:03 by gude-jes          #+#    #+#              #
#    Updated: 2024/06/19 15:04:00 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
MLXFLAGS 	= -L ./lib/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
NAME		= so_long
NAME_BONUS	= so_long_bonus

INC			= -I./includes
RM			= rm -rf

GENERAL		= main init dead
RENDER		= render_map render_window
MOVEMENT	= movement movement_utils
MAP			= check_map1 check_map2 checker map_utils
#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#
VPATH 		= src src/map\
				src/movement\
				src/renders
LIBS_PATH	= lib

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT 		= $(LIBFT_PATH)/libft.a
MLX_PATH	= $(LIBS_PATH)/minilibx-linux
MLX			= $(MLX_PATH)/libmlx_Linux.a

SRC			= $(addsuffix .c, $(GENERAL))\
			 $(addsuffix .c, $(RENDER))\
			 $(addsuffix .c, $(MOVEMENT))\
			 $(addsuffix .c, $(MAP))\

BONUS		= $(addprefix $(BONUS_PATH)/, $(addsuffix .c, $(FILES)))

OBJ_DIR		= obj
OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: deps $(NAME)

deps: 
	$(MAKE) -s -C $(LIBFT_PATH)
	$(MAKE) -s -C $(MLX_PATH)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJS) $(DEPS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	$(RM) $(OBJS)

fclean: clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libs
	@rm minilibx-linux.tgz

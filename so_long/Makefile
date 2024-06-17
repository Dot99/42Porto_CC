# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 08:48:03 by gude-jes          #+#    #+#              #
#    Updated: 2024/06/06 10:47:30 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME		= so_long
NAME_BONUS	= so_long_bonus

INCLUDE		= -I includes
RM			= rm -rf

FILES		= main parser dead
#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH	= src
BONUS_PATH	= bonus
LIBS_PATH	= lib

LIBFT_PATH	= $(LIBS_PATH)/libft
MLX_PATH	= $(LIBS_PATH)/mlx	

SRC			= $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))

BONUS		= $(addprefix $(BONUS_PATH)/, $(addsuffix .c, $(FILES)))


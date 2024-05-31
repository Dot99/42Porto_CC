# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/05/29 08:31:31 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMEC = client
NAMES = server
PRINTF = libftprintf.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)

clean :
		@make clean -C ft_printf
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		@make fclean -C ft_printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all clean fclean re
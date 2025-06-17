# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:30:37 by bdjoco            #+#    #+#              #
#    Updated: 2025/06/17 16:38:46 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/so_long.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)
	@echo "\e[1m\e[32mTout est compilé\e[0m ​👍​"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "\e[32mNettoyage des \e[0m\e[1mfichiers source\e[0m \e[32mterminé\e[0m 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "\e[32mNettoyage de \e[0m\e[1mlibftprintf.a\e[0m \e[32mterminé\e[0m 🧹"

re : fclean all

.PHONY: all clean fclean re

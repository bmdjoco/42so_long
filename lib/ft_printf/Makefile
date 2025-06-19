# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 11:40:39 by bdjoco            #+#    #+#              #
#    Updated: 2025/05/29 10:14:28 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/print_type.c \
		src/print_type_bis.c \
		src/def_type.c \
		src/def_type_bis.c \
		src/ft_printf.c \
		lib/ft_putchar_fd.c \
		lib/ft_putstr_fd.c \
		lib/ft_strlen.c \
		lib/ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all : $(NAME)
	@echo "Tout est compilé ​👍​"

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@echo "Nettoyage des fichiers source terminé 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "Nettoyage de libftprintf.a terminé 🧹"

re : fclean all

.PHONY: all clean fclean re

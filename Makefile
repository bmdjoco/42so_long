# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:30:37 by bdjoco            #+#    #+#              #
#    Updated: 2025/08/04 11:29:20 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilib/mlx -g3
MLXFLAGS = -L$(MLX) -lmlx_Linux -lXext -lX11

LIBFT = lib/libft/
FT_PRINTF = lib/ft_printf/
MLX = lib/mlx/

AR = ar rcs
RM = rm -f

SRC = src/so_long.c \
		src/error.c \
		src/map.c \
		src/map_check.c \
		src/map_utils.c \
		src/go_next_line.c \
		src/map_draw.c \
		src/game.c \
		src/img_utils.c \
		src/utils.c
OBJ = $(SRC:.c=.o)

LIBS = $(LIBFT)libft.a $(FT_PRINTF)libftprintf.a $(MLX)libmlx_Linux.a

MAKE = make -s -C

BOLD = \e[1m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

all : $(NAME)

$(NAME) : $(OBJ) $(LIBS)
	@echo "🔱 $(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) est compilé$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf $(MLXFLAGS) -o $(NAME) -no-pie

%.o: %.c so_long.h
	@echo "Compiling : $(PURPLE)$<$(NC)$(RESET)"
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT)libft.a:
	@$(MAKE) $(LIBFT)

$(FT_PRINTF)libftprintf.a:
	@$(MAKE) $(FT_PRINTF)

$(MLX)libmlx_Linux.a:
	@$(MAKE) $(MLX) > /dev/null 2>&1
	@echo "$(BOLD)$(PURPLE)Minilibx$(RESET) $(GREEN)est compilé $(RESET)​🔰​"

clean :
	@$(RM) $(OBJ)
	@echo "$(GREEN)Nettoyage des $(RESET)$(BOLD)fichiers source de so_long$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@$(MAKE) $(LIBFT) clean
	@$(MAKE) $(FT_PRINTF) clean

fclean : clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Nettoyage de $(RESET)$(BOLD)so_long.a$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@$(MAKE) $(LIBFT) fclean
	@$(MAKE) $(FT_PRINTF) fclean
	@$(MAKE) $(MLX) clean > /dev/null 2>&1

#----------------------------------------------------------------------#

test : all clean
	@echo "🔱 $(PURPLE)On cook$(RESET) 🔱"

#----------------------------------------------------------------------#

re : fclean all

.PHONY: all clean fclean re

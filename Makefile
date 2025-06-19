# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:30:37 by bdjoco            #+#    #+#              #
#    Updated: 2025/06/19 16:47:42 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx
MLXFLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lXrandr -lXcursor -lXrender -lXfixes -lXinerama -lXcomposite -lXdamage -lXxf86vm -lXau -lXdmcp

LIBFT = lib/libft/
FT_PRINTF = lib/ft_printf/
MLX = lib/minilibx/

AR = ar rcs
RM = rm -f

SRC = ./src/so_long.c
OBJ = $(SRC:.c=.o)

LIBS = $(LIBFT)libft.a $(FT_PRINTF)libftprintf.a $(MLX)libmlx_Linux.a

BOLD = \e[1m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

all : $(NAME)

$(NAME) : $(OBJ) $(LIBS)
	@echo "$(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) est compilé$(RESET) ​👍​"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf $(MLXFLAGS) -o $(NAME)

%.o: %.c so_long.h
	@echo "Compiling : $(PURPLE)$<$(NC)$(RESET)"
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

$(FT_PRINTF)libftprintf.a:
	@make -C $(FT_PRINTF)

clean :
	@$(RM) $(OBJ)
	@echo "$(GREEN)Nettoyage des $(RESET)$(BOLD)fichiers source$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@make -C $(LIBFT) clean
	@make -C $(FT_PRINTF) clean

fclean : clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Nettoyage de $(RESET)$(BOLD)libftprintf.a$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@make -C $(LIBFT) fclean
	@make -C $(FT_PRINTF) fclean

re : fclean all

.PHONY: all clean fclean re

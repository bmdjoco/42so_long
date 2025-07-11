/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:11:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/11 11:14:17 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/mlx/mlx.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

# ifndef TYLE_SIZE
#  define TYLE_SIZE 64
# endif

typedef struct	s_slot {
	void	*img;
	char	s;
}				t_slot;

typedef struct	s_map {
	int		width;
	int		height;
	t_slot	**map;
}				t_map;

typedef struct s_gc_node {
	void	*ptr;
	struct	s_gc_node *next;
} t_gc_node;

/**/
typedef struct	s_pos {
	int		x;
	int		y;
	void	*player;
}				t_pos;

typedef struct	s_game {
	int		score;
	void	*mlx;
	void	*win;
	t_map	*carte;
	t_pos	*pos;
}				t_game;

int		check_size(char *file);
int		get_lenght(char *file);
int		get_nb_line(char *file);
int		put_player(t_game *vars);
int		check_bord(t_map *carte);
int		is_necessary(char **map);
int		close_window(void *param);
int		check_in_out(t_map	*carte);
int		move(t_game *vars, int x, int y);

char	**to_char_map(t_map *carte);

void	gc_free_all(void);
void	print_map(char **map);
void	end_game(t_game *vars);
void	draw_map(t_game *vars);
void	*gc_malloc(size_t size);
void	kill_img_all(t_game *vars);
void	free_dtab(char **tab, int i);
void	free_tmap(t_slot **tab, int i);
void	*get_image(t_game *vars, char c);
void	is_drop_case(t_game *vars, int x, int y);
void	is_movable_case(t_game *vars, int x, int y);
void	put_img_win(t_game *vars, int x, int y, char c);
void	floodfil_pv(char **map, int i, int j, int height, int *score);


t_map	*init_map(char *file);

t_pos	*get_pos(t_map	*carte);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:11:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/27 19:26:47 by bdjoco           ###   ########.fr       */
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

typedef struct	s_slot {
	void	*img;
	char	s;
}				t_slot;

typedef struct	s_map_re {
	int		width : 32;
	int		height : 14;
	t_slot	**map;
}				t_map_re;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_map_re	*carte;
}				t_vars;

typedef struct s_gc_node {
	void	*ptr;
	struct	s_gc_node *next;
} t_gc_node;

typedef struct	s_pos {
	int	x;
	int	y;
}				t_pos;

int		check_size(char *file);
int		get_lenght(char *file);
int		get_nb_line(char *file);
int		close_window(void *param);
int		check_bord_re(t_map_re *carte);
int		check_in_out_re(t_map_re	*carte);

void	gc_free_all(void);
void	print_map(char **map);
void	draw_map(t_vars *vars);
void	*gc_malloc(size_t size);
void	kill_img_all(t_vars *vars);

t_map_re	*init_map_re(char *file);




#endif

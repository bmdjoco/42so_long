/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:11:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/25 01:34:23 by bdjoco           ###   ########.fr       */
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


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_map {
	int		width : 32;
	int		height : 14;
	char	**map;
}				t_map;

typedef struct s_gc_node {
	void	*ptr;
	struct	s_gc_node *next;
} t_gc_node;

int		check_bord(t_map *carte);
int		check_in_out(t_map	*carte);
int		close_window(void *param);

void	*gc_malloc(size_t size);
void	gc_free_all(void);

t_map	*init_map(char *file);

#endif

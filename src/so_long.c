/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/20 17:44:16 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	gc_free_all();
	mlx_destroy_window((*vars).mlx, (*vars).win);
	mlx_destroy_display((*vars).mlx);
	free((*vars).mlx);
	exit(0);
	return (0);
}

int	get_height(char **map)
{
	int	h;

	h = 0;
	while(map[h])
		h++;
	return (h);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("| %c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_map	*init_map(char *file)
{
	char	*buff;
	t_map	*carte;
	int		fd;
	int		f;
	int		h;
	int		w;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("fd error\n"), NULL);
	buff = (char *) gc_malloc(sizeof(char) * 2);
	if(!buff)
		return (NULL);
	f = read(fd, buff,BUFFER_SIZE);
	carte = (t_map *) gc_malloc(sizeof(t_map));
	if(!carte)
		return (gc_free_all(), NULL);
	carte->height = 14;
	carte->width = 32;
	carte->map = (char **) gc_malloc(sizeof(char *) * (carte->height + 1));
	if (!carte->map)
		return (gc_free_all(), NULL);
	h = 0;
	while(f)
	{
		if (h >= carte->height)
			return (gc_free_all(), NULL);
		w = 0;
		carte->map[h] = (char *) gc_malloc(sizeof(char) * (carte->width + 1));
		if (!carte->map[h])
			return (gc_free_all(), NULL);
		while (f > 0 && buff[0] != '\n')
		{
			if(w >= carte->width)
				return (gc_free_all(), NULL);
			carte->map[h][w] = buff[0];
			f = read(fd, buff,BUFFER_SIZE);
			w++;
		}
		if (buff[0] == '\n')
			f = read(fd, buff,BUFFER_SIZE);
		carte->map[h][w] = '\0';
		h++;
	}
	carte->map[h] = NULL;
	return (carte);
}

int main(void)
{
	t_vars	vars;
	t_map	*carte;

	vars.mlx = mlx_init();

	carte = init_map("assets/map.ber");
	if (!carte)
		return(mlx_destroy_window(vars.mlx, vars.win), mlx_destroy_display(vars.mlx), free(vars.mlx), 0);

	print_map(carte->map);

	vars.win = mlx_new_window(vars.mlx, carte->width * 50, carte->height * 50, "So Long");

	mlx_hook(vars.win, ON_DESTROY, 0L, close_window, &vars);

	mlx_loop(vars.mlx);
	return (0);
}

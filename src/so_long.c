/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/23 17:25:45 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	gc_free_all();
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
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

/*
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
	close(fd);
	carte->map[h] = NULL;
	return (carte);
}*/

t_map	*alloc_carte(void)
{
	t_map	*carte;

	carte = (t_map *) gc_malloc(sizeof(t_map));
	if(!carte)
		return (NULL);
	carte->height = 14;
	carte->width = 32;
	carte->map = (char **) gc_malloc(sizeof(char *) * (carte->height + 1));
	if (!carte->map)
		return (gc_free_all(), NULL);
	return (carte);
}

t_map	*init_map(char *file)
{
	t_map	*carte;
	char	*line;
	int		fd;
	int		i;
	int		h;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("fd error\n"), NULL);
	carte = alloc_carte();
	if (!carte)
		return (NULL);
	h = 0;
	line = get_next_line(fd);
	while (line)
	{
		if((int) ft_strlen(line) > carte->width)
			return (NULL);
		i = 0;
		while (line[i])
		{
			carte->map[h][i] = line[i];
			i++;
		}
		line = get_next_line(fd);
		h++;
	}
	carte->map[carte->height] = NULL;
	if (h > carte->height)
		return (gc_free_all(), NULL);
	return (carte);
}

int	key_press(int key, void *param)
{
	(void) param;
	if (key == XK_Up || key == XK_w)
		ft_printf("Up presser\n");
	else if (key == XK_Down || key == XK_s)
		ft_printf("Down presser\n");
	else if (key == XK_Left || key == XK_a)
		ft_printf("Left presser\n");
	else if (key == XK_Right || key == XK_d)
		ft_printf("Right presser\n");
	else if (key == XK_Escape)
		return (gc_free_all(), close_window(param));
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_map	*carte;

	vars.mlx = mlx_init();

	carte = init_map("assets/map.ber");

	vars.win = mlx_new_window(vars.mlx, carte->width * 50, carte->height * 50, "So Long");

	if (!carte)
		return(close_window(&vars));
	print_map(carte->map);

	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);

	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

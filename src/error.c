/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:39:34 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/20 14:05:22 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		exit(0);
	if (game->carte)
	{
		kill_img_all(game);
		free_tmap(game->carte->map, game->carte->height - 1);
		free(game->carte);
	}
	if (game->pos && game->pos->player)
	{
		mlx_destroy_image(game->mlx, game->pos->player);
		free(game->pos);
	}
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int	check_map(char *file)
{
	int		i;
	int		t;
	int		fd;
	char	*res;

	t = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	res = get_next_line(fd);
	while (res)
	{
		i = -1;
		while (res[++i])
			if (!valid_char(res[i]))
				t--;
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	if (t < 0)
		return (0);
	return (1);
}

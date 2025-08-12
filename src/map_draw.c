/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:22:24 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/12 12:25:48 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image(t_game *game, char c)
{
	int	t_size;

	t_size = 64;
	if (c == '1')
		return (mlx_xpm_file_to_image((*game).mlx,
				"textures/wall.xpm", &t_size, &t_size));
	else if (c == '0')
		return (mlx_xpm_file_to_image((*game).mlx,
				"textures/ground.xpm", &t_size, &t_size));
	else if (c == 'P')
		return (mlx_xpm_file_to_image((*game).mlx,
				"textures/spawn.xpm", &t_size, &t_size));
	else if (c == 'E')
		return (mlx_xpm_file_to_image((*game).mlx,
				"textures/escape.xpm", &t_size, &t_size));
	else
		return (mlx_xpm_file_to_image((*game).mlx,
				"textures/drop.xpm", &t_size, &t_size));
}

void	kill_img_all(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game).carte->height)
	{
		j = 0;
		while (j < (*game).carte->width)
		{
			if ((*game).carte->map[i][j].img)
				mlx_destroy_image((*game).mlx, (*game).carte->map[i][j].img);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*game).carte->height)
	{
		j = 0;
		while (j < (*game).carte->width)
		{
			(*game).carte->map[i][j].img = get_image(game,
					(*game).carte->map[i][j].s);
			if (!(*game).carte->map[i][j].img)
				close_window(game);
			j++;
		}
	}
	i = -1;
	while (++i < (*game).carte->height)
	{
		j = -1;
		while (++j < (*game).carte->width)
		{
			put_img_win(game, j, i, 'm');
		}
	}
}

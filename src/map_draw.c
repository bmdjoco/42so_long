/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:22:24 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/05 14:26:46 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image(t_vars *vars, char c)
{
	int	t_size;

	t_size = 50;
	if (c == '1')
		return (mlx_xpm_file_to_image((*vars).mlx, "assets/img/wall.xpm", &t_size, &t_size));
	else if (c == '0')
		return (mlx_xpm_file_to_image((*vars).mlx, "assets/img/ground.xpm", &t_size, &t_size));
	else if (c == 'P')
		return (mlx_xpm_file_to_image((*vars).mlx, "assets/img/spawn.xpm", &t_size, &t_size));
	else if (c == 'E')
		return (mlx_xpm_file_to_image((*vars).mlx, "assets/img/escape.xpm", &t_size, &t_size));
	else
		return (mlx_xpm_file_to_image((*vars).mlx, "assets/img/drop.xpm", &t_size, &t_size));
}

void	kill_img_all(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*vars).carte->height)
	{
		j = 0;
		while (j < (*vars).carte->width)
		{
			if ((*vars).carte->map[i][j].img)
				mlx_destroy_image((*vars).mlx, (*vars).carte->map[i][j].img);
			j++;
		}
		i++;
	}
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*vars).carte->height)
	{
		j = 0;
		while (j < (*vars).carte->width)
		{
			(*vars).carte->map[i][j].img = get_image(vars, (*vars).carte->map[i][j].s);
			if (!(*vars).carte->map[i][j].img)
				close_window(vars);
			put_img_win(vars, j, i, 'm');
			j++;
		}
		i++;
	}
}

t_pos	*get_outdoor_pos(vars)
{
	t_pos	outdoor;
}

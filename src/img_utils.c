/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:52:31 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/28 16:25:07 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_drop_case(t_vars *vars, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = vars->pos->x + x;
	y_pos = vars->pos->y + y;
	mlx_destroy_image(vars->mlx, vars->carte->map[y_pos][x_pos].img);
	vars->carte->map[y_pos][x_pos].s = '0';
	vars->score++;
	vars->carte->map[y_pos][x_pos].img = get_image(vars, vars->carte->map[y_pos][x_pos].s);
	if (!vars->carte->map[y_pos][x_pos].img)
		close_window(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->carte->map[y_pos][x_pos].img, x_pos * 50, y_pos * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pos->player, x_pos * 50, y_pos * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->carte->map[y_pos - y][x_pos - x].img, (x_pos - x) * 50, (y_pos - y) * 50);
	vars->pos->x += x;
	vars->pos->y += y;
}

void	is_movable_case(t_vars *vars, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = vars->pos->x + x;
	y_pos = vars->pos->y + y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pos->player, x_pos * 50, y_pos * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->carte->map[y_pos - y][x_pos - x].img, (x_pos - x) * 50, (y_pos - y) * 50);
	vars->pos->x += x;
	vars->pos->y += y;
}

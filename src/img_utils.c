/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:52:31 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/28 17:51:18 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_win(t_vars *vars, int x, int y, char c)
{
	void	*img;

	if (c == 'p')
		img = vars->pos->player;
	else
		img = vars->carte->map[y][x].img;
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * TYLE_SIZE, y *TYLE_SIZE);
}

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
	put_img_win(vars, x_pos, y_pos, 'm');
	put_img_win(vars, x_pos, y_pos, 'p');
	put_img_win(vars, x_pos - x, y_pos - y, 'm');
	vars->pos->x += x;
	vars->pos->y += y;
}

void	is_movable_case(t_vars *vars, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = vars->pos->x + x;
	y_pos = vars->pos->y + y;
	put_img_win(vars, x_pos, y_pos, 'p');
	put_img_win(vars, x_pos - x, y_pos - y, 'm');
	vars->pos->x += x;
	vars->pos->y += y;
}

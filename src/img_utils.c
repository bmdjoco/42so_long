/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:52:31 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/28 15:26:35 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_win(t_game *game, int x, int y, char c)
{
	void	*img;

	if (c == 'p')
		img = game->pos->player;
	else
		img = game->carte->map[y][x].img;
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TYLE_SIZE, y * TYLE_SIZE);
}

void	is_drop_case(t_game *game, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->pos->x + x;
	y_pos = game->pos->y + y;
	mlx_destroy_image(game->mlx, game->carte->map[y_pos][x_pos].img);
	game->carte->map[y_pos][x_pos].s = '0';
	game->score++;
	game->carte->map[y_pos][x_pos].img = get_image(game,
			game->carte->map[y_pos][x_pos].s);
	if (!game->carte->map[y_pos][x_pos].img)
		close_window(game);
	put_img_win(game, x_pos, y_pos, 'm');
	put_img_win(game, x_pos, y_pos, 'p');
	put_img_win(game, x_pos - x, y_pos - y, 'm');
	game->pos->x += x;
	game->pos->y += y;
}

void	is_movable_case(t_game *game, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->pos->x + x;
	y_pos = game->pos->y + y;
	put_img_win(game, x_pos, y_pos, 'p');
	put_img_win(game, x_pos - x, y_pos - y, 'm');
	game->pos->x += x;
	game->pos->y += y;
}

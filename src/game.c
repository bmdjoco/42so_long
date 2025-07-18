/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:08:33 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/13 12:04:28 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_game *game)
{
	ft_printf("Score : %d pts.\n", game->score);
	close_window(game);
}


int	move(t_game *game, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->pos->x;
	y_pos = game->pos->y;
	if (x_pos + x <= 0 || x_pos + x >= game->carte->width - 1
		|| y_pos + y <= 0 || y_pos + y >= game->carte->height - 1)
		return(0);
	if (game->carte->map[y_pos + y][x_pos + x].s == '1')
		return (0);
	else if (game->carte->map[y_pos + y][x_pos + x].s == 'C')
		is_drop_case(game, x, y);
	else if (game->carte->map[y_pos + y][x_pos + x].s == '0'
		|| game->carte->map[y_pos + y][x_pos + x].s == 'P')
		is_movable_case(game, x, y);
	else if (game->carte->map[y_pos + y][x_pos + x].s == 'E')
		end_game(game);
	return (1);
}

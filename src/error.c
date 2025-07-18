/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:39:34 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/13 12:49:11 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		exit(0);
	if(game->carte)
		kill_img_all(game);
	if(game->pos && game->pos->player)
		mlx_destroy_image(game->mlx, game->pos->player);
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

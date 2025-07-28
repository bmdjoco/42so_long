/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:39:34 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/28 15:20:59 by bdjoco           ###   ########.fr       */
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

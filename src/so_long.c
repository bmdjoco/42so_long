/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/11 11:46:28 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == XK_Up || key == XK_w)
		move(game, 0, -1);
	else if (key == XK_Down || key == XK_s)
		move(game, 0, 1);
	else if (key == XK_Left || key == XK_a)
		move(game, -1, 0);
	else if (key == XK_Right || key == XK_d)
		move(game, 1, 0);
	else if (key == XK_Escape)
		return (ft_printf("Close\n"), close_window(game));
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->carte = NULL;
	game->score = 0;
	game->pos = NULL;
}

static int	define_game(t_game *game)
{
	int		s_width;
	int		s_height;

	game->mlx = mlx_init();
	game->carte = init_map("../assets/map.ber");
	if (!game->carte)
		return(close_window(&game));
	mlx_get_screen_size(game->mlx, &s_width, &s_height);
	if (s_width < game->carte->width * TYLE_SIZE
		|| s_height < game->carte->height * TYLE_SIZE)
		return (ft_putstr_fd("Error: map too big\n", 2), close_window(&game));
	game->win = mlx_new_window(game->mlx, game->carte->width * TYLE_SIZE,
		game->carte->height * TYLE_SIZE, "So Long");
	draw_map(game);
	game->pos = get_pos(game->carte);
	if (!game->pos)
		return(close_window(&game));
	put_player(game);
	return (1);
}

int main(void)
{
	t_game	game;

	init_game(&game);
	define_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

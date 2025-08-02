/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/08/02 15:19:03 by bdjoco           ###   ########.fr       */
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
		return (close_window(game));
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->carte = NULL;
	game->score = 0;
	game->pos = NULL;
	game->move = 0;
}

static int	define_game(t_game *game, char *file)
{
	int		s_width;
	int		s_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->carte = init_map(file);
	if (!game->carte)
		return (mlx_destroy_display(game->mlx), free(game->mlx), exit(0), 0);
	mlx_get_screen_size(game->mlx, &s_width, &s_height);
	if (s_width < game->carte->width * TYLE_SIZE
		|| s_height < game->carte->height * TYLE_SIZE)
		return (ft_putstr_fd("Error: map too big\n", 2),
			close_window(game));
	game->win = mlx_new_window(game->mlx, game->carte->width * TYLE_SIZE,
			game->carte->height * TYLE_SIZE, "So Long");
	draw_map(game);
	game->pos = get_pos(game->carte);
	if (!game->pos)
		return (close_window(&game));
	put_player(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./so_long <map.ber>\n", 1), 0);
	init_game(&game);
	define_game(&game, av[1]);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/28 17:40:56 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (key == XK_Up || key == XK_w)
		move(vars, 0, -1);
	else if (key == XK_Down || key == XK_s)
		move(vars, 0, 1);
	else if (key == XK_Left || key == XK_a)
		move(vars, -1, 0);
	else if (key == XK_Right || key == XK_d)
		move(vars, 1, 0);
	else if (key == XK_Escape)
		return (ft_printf("Close\n"), close_window(vars));
	return (0);
}

static void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->carte = NULL;
	vars->score = 0;
	vars->pos = NULL;
}

int main(void)
{
	t_vars	vars;

	init_vars(&vars);
	vars.mlx = mlx_init();
	vars.carte = init_map("assets/map.ber");
	if (!vars.carte)
		return(close_window(&vars));
	vars.win = mlx_new_window(vars.mlx, vars.carte->width * TYLE_SIZE, vars.carte->height * TYLE_SIZE, "So Long");
	draw_map(&vars);
	vars.pos = get_pos(vars.carte);
	if (!vars.pos)
		return(close_window(&vars));
	put_player(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

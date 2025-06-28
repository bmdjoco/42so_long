/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:08:33 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/28 17:29:51 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_vars *vars)
{
	ft_printf("Score : %d pts.\n", vars->score);
	close_window(vars);
}


int	move(t_vars *vars, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = vars->pos->x;
	y_pos = vars->pos->y;
	if (x_pos + x <= 0 || x_pos + x >= vars->carte->width - 1
		|| y_pos + y <= 0 || y_pos + y >= vars->carte->height - 1)
		return(0);
	if (vars->carte->map[y_pos + y][x_pos + x].s == '1')
		return (0);
	else if (vars->carte->map[y_pos + y][x_pos + x].s == 'C')
		is_drop_case(vars, x, y);
	else if (vars->carte->map[y_pos + y][x_pos + x].s == '0'
		|| vars->carte->map[y_pos + y][x_pos + x].s == 'P')
		is_movable_case(vars, x, y);
	else if (vars->carte->map[y_pos + y][x_pos + x].s == 'E')
		end_game(vars);
	return (1);
}

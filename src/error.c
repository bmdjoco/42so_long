/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:39:34 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/28 14:23:06 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if(vars->carte)
		kill_img_all(vars);
	if(vars->pos->player)
		mlx_destroy_image(vars->mlx, vars->pos->player);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	gc_free_all();
	exit(0);
	return (0);
}

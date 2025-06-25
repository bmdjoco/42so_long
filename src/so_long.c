/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:23 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/25 01:34:48 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("| %c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	key_press(int key, void *param)
{
	(void) param;
	if (key == XK_Up || key == XK_w)
		ft_printf("Up presser\n");
	else if (key == XK_Down || key == XK_s)
		ft_printf("Down presser\n");
	else if (key == XK_Left || key == XK_a)
		ft_printf("Left presser\n");
	else if (key == XK_Right || key == XK_d)
		ft_printf("Right presser\n");
	else if (key == XK_Escape)
		return (ft_printf("Close\n"), gc_free_all(), close_window(param));
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_map	*carte;

	vars.mlx = mlx_init();

	carte = init_map("assets/map.ber");

	vars.win = mlx_new_window(vars.mlx, carte->width * 50, carte->height * 50, "So Long");

	if (!carte)
		return(close_window(&vars));
	print_map(carte->map);

	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);

	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

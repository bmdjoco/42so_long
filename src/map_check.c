/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:52:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/25 11:40:30 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_bord(t_map *carte)
{
	int	i;
	int	j;

	i = 0;
	while (i < carte->height)
	{
		j = 0;
		while (carte->map[i][j])
		{
			if (carte->map[i][j] != '1'
				&& ((i == 0 || i == carte->height - 1)
				|| (j == 0 || j == carte->width - 1)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_in_out(t_map	*carte)
{
	int	i;
	int	j;
	int	nb_i;
	int	nb_o;

	i = 0;
	nb_i = 0;
	nb_o = 0;
	while (i < carte->height)
	{
		j = 0;
		while (carte->map[i][j])
		{
			if (carte->map[i][j] == 'P')
				nb_i++;
			else if (carte->map[i][j] == 'E')
				nb_o++;
			j++;
		}
		i++;
	}
	return (nb_i == 1 && nb_o == 1);
}

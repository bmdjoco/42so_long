/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:38:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/13 13:40:22 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tmap(t_slot **tab, int i)
{
	while(i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

void	free_dtab(char **tab, int i)
{
	while(i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

void	print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

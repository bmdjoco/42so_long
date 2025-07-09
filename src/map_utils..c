/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils..c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:22:19 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/09 18:19:13 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab, int i)
{
	while(i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char	**to_char_map(t_map *carte)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (carte->height + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < carte->height)
	{
		res[i] = malloc(sizeof(char) * (carte->width + 1));
		if (!res[i])
			return (free_tab(res, i - 1), NULL);
		j = 0;
		while (j < carte->width)
		{
			res[i][j] = carte->map[i][j].s;
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	floodfil_pv(char **map, int i, int j, int height, int *score)
{
	int	lenght;
	int	i;
	int	j;

	if(!map[i])
		return ;
	lenght = strlen(map[i]);
	if ((i < height && j < lenght) || map[i][j] == '1')
		return ;
	if(map[i][j] == 'C' || map[i][j] == 'E')
		*score = *score + 1;
	floodfil_pv(map, i - 1, j, height, score);
	floodfil_pv(map, i + 1, j, height, score);
	floodfil_pv(map, i, j - 1, height, score);
	floodfil_pv(map, i, j + 1, height, score);
}

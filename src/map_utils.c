/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:22:19 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/18 16:04:53 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**to_char_map(t_map *carte)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (carte->height + 1));
	if (!res)
		return (free_dtab(res, carte->height - 1), NULL);
	i = 0;
	while (i < carte->height)
	{
		res[i] = malloc(sizeof(char) * (carte->width + 1));
		if (!res[i])
			return (free_dtab(res, i - 1), NULL);
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

char	newchar(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return ('o');
}

void	floodfil_pv(char **map, int j, int i, int height)
{
	int	lenght;

	if(!map[0])
		return ;
	lenght = ft_strlen(map[i]);
	if (i >= height || j >= lenght || i < 0 || j < 0 || map[i][j] == '1'
		|| map[i][j] == 'o' || (map[i][j] >= 'a' && map[i][j] <= 'z'))
		return ;
	map[i][j] = newchar(map[i][j]);
	floodfil_pv(map, j - 1, i, height);
	floodfil_pv(map, j + 1, i, height);
	floodfil_pv(map, j, i - 1, height);
	floodfil_pv(map, j, i + 1, height);
}

int	can_access(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

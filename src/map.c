/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:14:16 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/27 18:28:20 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map	*alloc_carte(int *fd, char *file)
{
	t_map	*carte;

	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ft_printf("fd error\n"), NULL);
	carte = (t_map *) malloc(sizeof(t_map));
	if(!carte)
		return (NULL);
	carte->height = get_nb_line(file);
	if (carte->height == -1)
		return (free(carte), NULL);
	carte->width = get_lenght(file);
	if (carte->width == -1)
		return (free(carte), NULL);
	carte->map = (t_slot **) malloc(sizeof(t_slot *) * (carte->height));
	if (!carte->map)
		return (free(carte), NULL);
	return (carte);
}

static int	is_auth(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P')
		return (1);
	return (0);
}

static int	write_line(t_map *carte, int nb_l, int fd)
{
	int		i;
	char	*res;

	res = get_next_line(fd);
	if (!res)
		return (0);
	carte->map[nb_l] = (t_slot *) malloc(sizeof(t_slot) * (carte->width));
	i = 0;
	if (!carte->map[nb_l])
		return (free_tmap(carte->map, i - 1), free(carte), free(res), 0);
	while (res[i] && res[i] != '\n')
	{
		if (!is_auth(res[i]))
			return (free_tmap(carte->map, i), free(carte), free(res), 0);
		carte->map[nb_l][i].s = res[i];
		carte->map[nb_l][i].img = NULL;
		i++;
	}
	free(res);
	return (1);
}

static t_map	*init_map_end(t_map *carte, char **tab)
{
	t_pos	*pos;
	int		score;

	score = 0;
	pos = get_pos(carte);
	if (!pos)
		return (NULL);
	floodfil_pv(tab, pos->x, pos->y, carte->height, &score);
	if (score != is_necessary(tab))
		return (free_tmap(carte->map, carte->height - 1), free(carte), free(pos), NULL);
	return (free(pos), carte);
}

t_map	*init_map(char *file)
{
	t_map	*carte;
	char	**tab;
	int		fd;
	int		l;

	if (!check_size(file))
		return (NULL);
	carte = alloc_carte(&fd, file);
	if (!carte)
		return (NULL);
	l = 0;
	while (write_line(carte, l, fd))
		l++;
	if (!check_in_out(carte) || !check_bord(carte))
		return (NULL);
	tab = to_char_map(carte);
	if(!tab)
		return (NULL);
	return (init_map_end(carte, tab));
}

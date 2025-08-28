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
		return (ft_printf("Error: fd\n"), NULL);
	carte = (t_map *) malloc(sizeof(t_map));
	if (!carte)
		return (close(*fd), NULL);
	carte->height = get_nb_line(file);
	if (carte->height == -1)
		return (close(*fd), free(carte), NULL);
	carte->width = get_lenght(file);
	if (carte->width == -1)
		return (close(*fd), free(carte), NULL);
	carte->map = (t_slot **) malloc(sizeof(t_slot *) * (carte->height));
	if (!carte->map)
		return (close(*fd), free(carte), NULL);
	return (carte);
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
		return (carte->width = -1, free(res), 0);
	while (res[i] && res[i] != '\n')
	{
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
	int		*score;

	score = 0;
	pos = get_pos(carte);
	if (!pos)
		return (free_tmap(carte->map, carte->height - 1),
			free_dtab(tab, carte->height - 1), free(carte), NULL);
	floodfil_pv(tab, pos->x, pos->y, carte->height);
	if (!can_access(tab))
		return (free_tmap(carte->map, carte->height - 1),
			free_dtab(tab, carte->height - 1), free(carte), free(pos),
			ft_putstr_fd("Error: Map non valid\n", 2), NULL);
	return (free(pos), free_dtab(tab, carte->height - 1), carte);
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
		return (ft_putstr_fd("Error\n", 2), NULL);
	l = 0;
	while (write_line(carte, l, fd))
		l++;
	close(fd);
	if (carte->width == -1)
		return (free_tmap(carte->map, l - 1), free(carte),
			ft_putstr_fd("Error\n", 2), NULL);
	if (!check_in_out(carte) || !check_bord(carte))
		return (free_tmap(carte->map, l - 1), free(carte),
			ft_putstr_fd("Error: map invalid\n", 2), NULL);
	tab = to_char_map(carte);
	if (!tab)
		return (free_tmap(carte->map, l - 1), free(carte),
			ft_putstr_fd("Error\n", 2), NULL);
	return (init_map_end(carte, tab));
}

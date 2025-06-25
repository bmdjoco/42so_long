/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:59:52 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/25 02:04:28 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map	*alloc_carte(int *fd, char *file)
{
	t_map	*carte;

	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ft_printf("fd error\n"), NULL);
	carte = (t_map *) gc_malloc(sizeof(t_map));
	if(!carte)
		return (NULL);
	carte->height = 14;
	carte->width = 32;
	carte->map = (char **) gc_malloc(sizeof(char *) * (carte->height + 1));
	if (!carte->map)
		return (gc_free_all(), NULL);
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

	i = 0;
	if (nb_l >= carte->height)
		return (0);
	carte->map[nb_l] = (char *) gc_malloc(sizeof(char) * (carte->width + 1));
	if (!carte->map[nb_l])
		return (0);
	res = get_next_line(fd);
	if (!res)
		return (0);
	while (res[i] && res[i] != '\n')
	{
		if (!is_auth(res[i]))
			return (free(res), 0);
		if (i == carte->width)
			return (free(res), 0);
		carte->map[nb_l][i] = res[i];
		i++;
	}
	free(res);
	if (i != carte->width)
		return (0);
	return (1);
}

t_map	*init_map(char *file)
{
	t_map	*carte;
	int		fd;
	int		l;

	ft_printf("init_map start\n");
	carte = alloc_carte(&fd, file);
	if (!carte)
		return (NULL);
	l = 0;
	while (write_line(carte, l, fd))
		l++;
	ft_printf("%d\n", l);
	carte->map[l] = NULL;
	if (l != carte->height)
		return (NULL);
	if (!check_in_out(carte) || !check_bord(carte))
		return (NULL);
	return (carte);
}

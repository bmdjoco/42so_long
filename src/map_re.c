/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:14:16 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/27 18:28:20 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map_re	*alloc_carte_re(int *fd, char *file)
{
	t_map_re	*carte;

	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ft_printf("fd error\n"), NULL);
	carte = (t_map_re *) gc_malloc(sizeof(t_map_re));
	if(!carte)
		return (NULL);
	carte->height = get_nb_line(file);
	if (carte->height == -1)
		return (NULL);
	carte->width = get_lenght(file);
	if (carte->width == -1)
		return (NULL);
	carte->map = (t_slot **) gc_malloc(sizeof(t_slot *) * (carte->height));
	if (!carte->map)
		return (NULL);
	return (carte);
}

static int	is_auth(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P')
		return (1);
	return (0);
}

static int	write_line(t_map_re *carte, int nb_l, int fd)
{
	int		i;
	char	*res;

	res = get_next_line(fd);
	if (!res)
		return (0);
	carte->map[nb_l] = (t_slot *) gc_malloc(sizeof(t_slot) * (carte->width));
	if (!carte->map[nb_l])
		return (free(res), 0);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		if (!is_auth(res[i]))
			return (free(res), 0);
		carte->map[nb_l][i].s = res[i];
		carte->map[nb_l][i].img = NULL;
		i++;
	}
	free(res);
	return (1);
}

t_map_re	*init_map_re(char *file)
{
	t_map_re	*carte;
	int		fd;
	int		l;

	if (!check_size(file))
		return (NULL);
	carte = alloc_carte_re(&fd, file);
	if (!carte)
		return (NULL);
	l = 0;
	while (write_line(carte, l, fd))
		l++;
	if (!check_in_out_re(carte) || !check_bord_re(carte))
		return (NULL);
	return (carte);
}

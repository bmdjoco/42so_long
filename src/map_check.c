/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:35:31 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/27 18:03:50 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief renvoie 1 si il n'y a pas de probleme de taille ou 0
 */
int	check_size(char *file)
{
	int	w;
	int	h;

	h = get_nb_line(file);
	if (h < 3)
		return (ft_printf("La map ne contien pas sufisament de ligne\n"), 0);
	w = get_lenght(file);
	if (w == -1)
		return (ft_printf("La map contien des ligne de taille differente\n"), 0);
	else if (w < 3)
		return (ft_printf("La map contien des ligne pas suffisament grande\n"), 0);
	if (w < 5 && h < 5)
		return (ft_printf("La map est trop petite\n"), 0);
	return (1);
}

/**
 * @brief renvoie 1 si il n'y a que des mur aux bord de la map ou 0
 */
int	check_bord(t_map *carte)
{
	int	i;
	int	j;

	i = 0;
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			if (carte->map[i][j].s != '1'
				&& ((i == 0 || i == carte->height - 1)
				|| (j == 0 || j == carte->width - 1)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief renvoie 1 si il n'y qu'une seul entre et sortie ou 0
 */
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
		while (j < carte->width)
		{
			if (carte->map[i][j].s == 'P')
				nb_i++;
			else if (carte->map[i][j].s == 'E')
				nb_o++;
			j++;
		}
		i++;
	}
	return (nb_i == 1 && nb_o == 1);
}

t_pos	*get_pos(t_map	*carte)
{
	int		i;
	int		j;
	t_pos	*pos;

	i = 0;
	pos = (t_pos *) malloc(sizeof(t_pos));
	if(!pos)
		return (free_tmap(carte->map, carte->height - 1), free(carte), NULL);
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			if (carte->map[i][j].s == 'P')
			{
				pos->x = j;
				pos->y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (free_tmap(carte->map, carte->height - 1), free(carte), free(pos), NULL);
}

int	put_player(t_game *game)
{
	int	sityle;

	sityle = TYLE_SIZE;
	game->pos->player = mlx_xpm_file_to_image(game->mlx, "assets/img/player/initial.xpm", &sityle, &sityle);
	if(!game->pos->player)
		return (close_window(game), 0);
	put_img_win(game, game->pos->x, game->pos->y, 'p');
	return (1);
}

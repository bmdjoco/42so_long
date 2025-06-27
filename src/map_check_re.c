/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_re.c                                     :+:      :+:    :+:   */
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
int	check_bord_re(t_map_re *carte)
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
int	check_in_out_re(t_map_re	*carte)
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

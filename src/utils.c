/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:38:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/11 11:13:01 by bdjoco           ###   ########.fr       */
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

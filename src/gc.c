/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:26:41 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/25 01:34:29 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_gc_node *gc_list = NULL;

void	*gc_malloc(size_t size)
{
	void		*ptr;
	t_gc_node	*new_node;

	ptr = malloc(size);
	if (!ptr)
		return NULL;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		free(ptr);
		return NULL;
	}
	new_node->ptr = ptr;
	new_node->next = gc_list;
	gc_list = new_node;
	return (ptr);
}

void	gc_free_all(void)
{
	t_gc_node	*tmp;

	while (gc_list)
	{
		tmp = gc_list;
		gc_list = gc_list->next;
		free(tmp->ptr);
		free(tmp);
	}
}

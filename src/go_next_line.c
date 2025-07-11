/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:28:38 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/11 11:25:44 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	ssize_t	is_end;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || !stash)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		is_end = read(fd, buff, BUFFER_SIZE);
		if (is_end < 1)
			break ;
		buff[is_end] = '\0';
		tmp = ft_strjoin(stash, buff);
		if (!tmp)
			return (free(buff), NULL);
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

/**
 * @brief lis un fichier ligne par ligne
 *
 * @return renvoie 1 si le fichier n'est pas fini sinon 0
 */
static int	go_next_line(int fd)
{
	static char	*stash;
	char		*n_stash;
	size_t		i;

	if (!stash)
		stash = ft_calloc(1, 1);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, 0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	n_stash = ft_strdup(stash + i);
	if (!n_stash)
		return (free(n_stash), 0);
	free(stash);
	stash = n_stash;
	return (1);
}
/**
 * @brief renvoie le nombre de ligne d'un fichier
 *
 * @return renvoie le nombre de ligne ou -1 dans le cas ou l'on arrive pas a acceder au fichier'
 */
int	get_nb_line(char *file)
{
	int	fd;
	int	nb;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("fd error\n"), -1);
	nb = 0;
	while (go_next_line(fd))
		nb++;
	close(fd);
	return (nb);
}
/**
 * @brief renvoie la taille des ligne d'un fichier
 *
 * @return renvoie la lenght sans le '\\n' ou -1 dans le cas ou les lignes n'ont pas toute la meme taille
 */
int	get_lenght(char *file)
{
	int		fd;
	int		len;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("fd error\n"), -1);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), -1);
	len = ft_strlen(str);
	free(str);
	str = get_next_line(fd);
	while (str)
	{
		if(len != (int) ft_strlen(str))
			return (close(fd), free(str), -1);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (len - 1);
}

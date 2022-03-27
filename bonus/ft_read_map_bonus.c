/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:27 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:28 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_get_line_count(char *path, t_game *game)
{
	int		fd;
	int		line_count;
	size_t	width;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_and_exit("File is empty or it can not be read.\n", game);
	line_count = 0;
	s = get_next_line(fd);
	if (!s || !s[0])
		ft_error_and_exit("File is empty or it can not be read.\n", game);
	width = ft_strlen(s);
	while (s)
	{
		line_count++;
		free(s);
		s = get_next_line(fd);
		ft_check_mapwidth(fd, s, width, game);
	}
	close(fd);
	ft_check_linecount_and_exit(game, line_count);
	return (line_count);
}

static char	**ft_alloc_map(int count, t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		ft_error_and_exit("Can not create a map from file.\n", game);
	map[count] = NULL;
	return (map);
}

char	**ft_read_map(char *path, t_game *game)
{
	int		fd;
	char	*s;
	int		line_count;
	char	**map;
	int		i;

	ft_check_mappath(path, game);
	line_count = ft_get_line_count(path, game);
	map = ft_alloc_map(line_count, game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error_and_exit("File is empty or it can not be read.\n", game);
	}
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		map[i++] = s;
		s = get_next_line(fd);
	}
	close(fd);
	ft_error_after_secondread(i, line_count, map, game);
	return (map);
}

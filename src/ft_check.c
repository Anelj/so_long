/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:17:21 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:17:35 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ifallelements_avail(t_game *game, char **map)
{
	if (game->collectibles > 0 && game->exits > 0 && game->players == 1)
		return (1);
	ft_free_trying_tofill_tiles(game, map, "Wrong amount of elements.\n");
	return (1);
}

void	ft_check_mappath(char *path, t_game *game)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4))
		ft_error_and_exit("Path is not valid.\n", game);
}

int	ft_check_type(char **map, int y, int x, t_game *game)
{
	if (map[y][x] != 'E' && map[y][x] != '0' && map[y][x] != '1'
		&& map[y][x] != 'C' && map[y][x] != 'P')
		return (1);
	if ((x == 0 || y == 0 || x == (game->widthpx) / 64 - 1
			|| y == (game->hightpx) / 64 - 1) && map[y][x] != '1')
		return (1);
	if (map[y][x] == 'P' && game->players == 1)
		return (1);
	if (map[y][x] == 'P')
		game->players = 1;
	else if (map[y][x] == 'C')
		game->collectibles++;
	else if (map[y][x] == 'E')
		game->exits++;
	return (0);
}

void	ft_check_mapwidth(int fd, char *s, size_t width, t_game *game)
{
	if (s && (ft_strlen(s) != width))
	{
		free(s);
		close(fd);
		get_next_line(fd);
		ft_error_and_exit("Lines are different in the map.\n", game);
	}
}

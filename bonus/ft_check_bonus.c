/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:34 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:19:36 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_setmine(t_game *game, char **map, int x, int y)
{
	if (x && y)
	{
		if (map[y][x - 1] == '0' || map[y][x + 1] == '0')
		{
			game->tiles[y][x].isv = 0;
		}
		else if (map[y - 1][x] == '0' || map[y + 1][x] == '0')
			game->tiles[y][x].isv = 1;
		else
			game->tiles[y][x].isv = -1;
		game->tiles[y][x].isup_or_left = 0;
		game->tiles[y][x].freeze = 30;
	}
}

int	ft_check_type(char **map, int y, int x, t_game *game)
{
	if (map[y][x] != 'E' && map[y][x] != '0' && map[y][x] != '1'
		&& map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'M')
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
	else if (map[y][x] == 'M')
		ft_setmine(game, map, x, y);
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

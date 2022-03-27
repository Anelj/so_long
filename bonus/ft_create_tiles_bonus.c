/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tiles_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:40 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:19:42 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_fill_tiles(char **map, t_tile **tiles, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hightpx / 64)
	{
		x = 0;
		while (x < game->widthpx / 64)
		{
			if (ft_check_type(map, y, x, game))
				ft_free_trying_tofill_tiles(
					game, map, "Wrong chars, their position or amount.\n");
			tiles[y][x].x = x * 64;
			tiles[y][x].y = y * 64;
			tiles[y][x].type = map[y][x];
			if (map[y][x] == 'P')
				game->player.tile = tiles[y][x];
			x++;
		}
		if (map[y][x] != '\n' && map[y][x] != '\0')
			ft_free_trying_tofill_tiles(
				game, map, "Lines are different in the file.\n");
		y++;
	}
	ft_check_ifallelements_avail(game, map);
}

static t_tile	**ft_alloc_widthoftiles(char **map, t_tile **tiles, int len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		tiles[i] = (t_tile *)malloc(sizeof(t_tile) * (len));
		if (!tiles[i])
		{
			while (i)
			{
				free(tiles[--i]);
			}
			free(tiles);
			return (NULL);
		}
		i++;
	}
	return (tiles);
}

static t_tile	**ft_alloc_tiles(char **map, t_game *game)
{
	t_tile	**tiles;
	int		i;
	int		len;

	i = 0;
	while (map[i])
		i++;
	game->hightpx = 64 * i;
	tiles = malloc(sizeof(t_tile *) * (i + 1));
	if (!tiles)
		return (NULL);
	tiles[i] = NULL;
	len = 0;
	while (map[0][len] != '\n')
		len++;
	game->widthpx = 64 * (len);
	return (ft_alloc_widthoftiles(map, tiles, len));
}

t_tile	**ft_create_tiles_from_map(char **map, t_game *game)
{
	game->tiles = ft_alloc_tiles(map, game);
	if (!(game->tiles))
	{
		free(game);
		ft_free_map(map);
		ft_error_and_exit(
			"Can not allocate memory for tiles\n", game);
	}
	ft_fill_tiles(map, game->tiles, game);
	return (game->tiles);
}

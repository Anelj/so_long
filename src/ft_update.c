/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:18:37 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:18:38 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_helper(t_game *game, t_tile **tiles, int x, int y)
{
	void	*img;

	while (y < game->hightpx / 64)
	{
		x = 0;
		while (x < game->widthpx / 64)
		{
			if (tiles[y][x].type == '1')
				img = game->img_wall;
			else if (tiles[y][x].type == '0')
				img = game->img_empty;
			else if (tiles[y][x].type == 'E')
				img = game->img_exit;
			else if (tiles[y][x].type == 'P')
				img = game->img_player;
			else if (tiles[y][x].type == 'C')
				img = game->img_collectable;
			mlx_put_image_to_window(
				game->mlx, game->window, img, tiles[y][x].x, tiles[y][x].y);
			x++;
		}
		y++;
	}
}

int	ft_update(void *g)
{
	t_tile	**tiles;
	int		x;
	int		y;
	t_game	*game;

	game = (t_game *) g;
	tiles = game->tiles;
	x = 0;
	y = 0;
	ft_update_helper(game, tiles, x, y);
	return (0);
}

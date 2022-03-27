/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:18:12 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:18:13 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_player_down(t_game *game)
{
	t_player	player;
	t_tile		**tiles;
	t_tile		down_tile;
	int			x;
	int			y;

	tiles = game->tiles;
	player = game->player;
	x = player.tile.x / 64;
	y = player.tile.y / 64;
	down_tile = tiles[y + 1][x];
	if (down_tile.type == '1'
		|| (down_tile.type == 'E' && game->collectibles != 0))
		return (0);
	if (down_tile.type == 'E')
	{
		ft_destroy_game(game);
		exit(0);
	}
	if (down_tile.type == 'C')
		(game->collectibles)--;
	tiles[y][x].type = '0';
	tiles[y + 1][x].type = 'P';
	game->player.tile = tiles[y + 1][x];
	return (1);
}

int	ft_move_player_left(t_game *game)
{
	t_player	player;
	t_tile		**tiles;
	t_tile		left_tile;
	int			x;
	int			y;

	tiles = game->tiles;
	player = game->player;
	x = player.tile.x / 64;
	y = player.tile.y / 64;
	left_tile = tiles[y][x - 1];
	if (left_tile.type == '1'
		|| (left_tile.type == 'E' && game->collectibles != 0))
		return (0);
	if (left_tile.type == 'E')
	{
		ft_destroy_game(game);
		exit(0);
	}
	if (left_tile.type == 'C')
		(game->collectibles)--;
	tiles[y][x].type = '0';
	tiles[y][x - 1].type = 'P';
	game->player.tile = tiles[y][x - 1];
	return (1);
}

int	ft_move_player_right(t_game *game)
{
	t_player	player;
	t_tile		**tiles;
	t_tile		right_tile;
	int			x;
	int			y;

	tiles = game->tiles;
	player = game->player;
	x = player.tile.x / 64;
	y = player.tile.y / 64;
	right_tile = tiles[y][x + 1];
	if (right_tile.type == '1'
		|| (right_tile.type == 'E' && game->collectibles != 0))
		return (0);
	if (right_tile.type == 'E')
	{
		ft_destroy_game(game);
		exit(0);
	}
	if (right_tile.type == 'C')
		(game->collectibles)--;
	tiles[y][x].type = '0';
	tiles[y][x + 1].type = 'P';
	game->player.tile = tiles[y][x + 1];
	return (1);
}

int	ft_move_player_up(t_game *game)
{
	t_player	player;
	t_tile		**tiles;
	t_tile		up_tile;

	tiles = game->tiles;
	player = game->player;
	up_tile = tiles[player.tile.y / 64 - 1][player.tile.x / 64];
	if (up_tile.type == '1' || (up_tile.type == 'E' && game->collectibles != 0))
		return (0);
	if (up_tile.type == 'E')
	{
		ft_destroy_game(game);
		exit(0);
	}
	if (up_tile.type == 'C')
		(game->collectibles)--;
	tiles[player.tile.y / 64][player.tile.x / 64].type = '0';
	tiles[player.tile.y / 64 - 1][player.tile.x / 64].type = 'P';
	game->player.tile = tiles[player.tile.y / 64 - 1][player.tile.x / 64];
	return (1);
}

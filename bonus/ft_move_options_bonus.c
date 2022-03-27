/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_options_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:11 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:12 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_checktile_tomove(t_tile tile, t_game *game)
{
	if (tile.type == '1'
		|| (tile.type == 'E' && game->collectibles != 0))
		return (0);
	if (tile.type == 'E' || tile.type == 'M')
	{
		if (tile.type == 'M')
			game->won = 0;
		else
			game->won = 1;
		game->game_end = 1;
		return (0);
	}
	if (tile.type == 'C')
		(game->collectibles)--;
	return (1);
}

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
	if (!ft_checktile_tomove(down_tile, game))
		return (0);
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
	if (!ft_checktile_tomove(left_tile, game))
		return (0);
	tiles[y][x].type = '0';
	tiles[y][x - 1].type = 'P';
	game->player.tile = tiles[y][x - 1];
	if (game->player.lr == 2)
	{
		game->player.curimg = game->player.img1;
		game->player.lr = 1;
	}
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
	if (!ft_checktile_tomove(right_tile, game))
		return (0);
	tiles[y][x].type = '0';
	tiles[y][x + 1].type = 'P';
	game->player.tile = tiles[y][x + 1];
	if (game->player.lr == 1)
	{
		game->player.curimg = game->player.img2;
		game->player.lr = 2;
	}
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
	if (!ft_checktile_tomove(up_tile, game))
		return (0);
	tiles[player.tile.y / 64][player.tile.x / 64].type = '0';
	tiles[player.tile.y / 64 - 1][player.tile.x / 64].type = 'P';
	game->player.tile = tiles[player.tile.y / 64 - 1][player.tile.x / 64];
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mine1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:05 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:06 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_setfreezed_mine(t_game *game, int x, int y)
{
	if (game->tiles[y][x - 1].type == '0' || game->tiles[y][x + 1].type == '0')
	{
		game->tiles[y][x].isv = 0;
	}
	else if (game->tiles[y - 1][x].type == '0'
		|| game->tiles[y + 1][x].type == '0')
		game->tiles[y][x].isv = 1;
	else
		game->tiles[y][x].isv = -1;
	game->tiles[y][x].isup_or_left = 0;
}

void	ft_freeze_mine(t_game *game, int x, int y)
{
	if (game->tiles[y][x - 1].type != '0' && game->tiles[y][x + 1].type != '0'
		&& game->tiles[y - 1][x].type != '0'
		&& game->tiles[y + 1][x].type != '0'
		&& game->tiles[y][x - 1].type != 'P'
		&& game->tiles[y][x + 1].type != 'P'
		&& game->tiles[y - 1][x].type != 'P'
		&& game->tiles[y + 1][x].type != 'P')
	{
		game->tiles[y][x].isv = -1;
	}
}

void	*ft_mine_sprite(t_game *game)
{
	void	*img;

	if (game->mine.frame == 1)
	{
		img = game->mine.img1;
	}
	else
	{
		img = game->mine.img2;
	}
	return (img);
}

int	ft_ismine_moved(t_game *game, int x, int y, t_tile tile)
{
	if (game->tiles[y][x].type == '0')
	{
		game->tiles[y][x].type = 'M';
		game->tiles[y][x].isup_or_left = tile.isup_or_left;
		game->tiles[y][x].isv = tile.isv;
		game->tiles[y][x].freeze = tile.freeze;
		return (1);
	}
	else if (game->tiles[y][x].type == 'P')
	{
		if (!game->game_end)
		{
			game->won = 0;
			game->game_end = 1;
		}
		return (1);
	}
	return (0);
}

int	ft_mine_move(t_game *game, int x, int y)
{
	if (--(game->tiles[y][x].freeze))
		return (1);
	else
		game->tiles[y][x].freeze = 30;
	if (game->tiles[y][x].isv == -1)
		ft_setfreezed_mine(game, x, y);
	else
		ft_freeze_mine(game, x, y);
	if (game->tiles[y][x].isv == 1)
	{
		return (ft_mine_movev(game, x, y));
	}
	else if (game->tiles[y][x].isv == 0)
		return (ft_mine_moveg(game, x, y));
	return (1);
}

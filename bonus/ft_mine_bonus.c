/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:59 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:01 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_mine_move_left(t_game *game, int x, int y)
{
	if (ft_ismine_moved(game, x - 1, y, game->tiles[y][x]))
	{
		if (game->game_end)
			return (0);
		game->tiles[y][x].type = '0';
		return (1);
	}
	else
	{
		game->tiles[y][x].isup_or_left = 0;
		return (ft_mine_moveg(game, x, y));
	}
}

int	ft_mine_moveg(t_game *game, int x, int y)
{
	if (game->tiles[y][x].isup_or_left)
	{
		if (!ft_mine_move_left(game, x, y))
			return (0);
	}
	else
	{
		if (ft_ismine_moved(game, x + 1, y, game->tiles[y][x]))
		{
			if (game->game_end)
				return (0);
			game->tiles[y][x].type = '0';
		}
		else
		{
			game->tiles[y][x].isup_or_left = 1;
			ft_mine_move(game, x, y);
		}
	}
	return (1);
}

int	ft_mine_moveup(t_game *game, int x, int y)
{
	if (ft_ismine_moved(game, x, y - 1, game->tiles[y][x]))
	{
		if (game->game_end)
			return (0);
		game->tiles[y][x].type = '0';
		return (1);
	}
	else
	{
		game->tiles[y][x].isup_or_left = 0;
		return (ft_mine_move(game, x, y));
	}
}

int	ft_mine_movev(t_game *game, int x, int y)
{
	if (game->tiles[y][x].isup_or_left)
	{
		if (!ft_mine_moveup(game, x, y))
			return (0);
	}
	else
	{
		if (ft_ismine_moved(game, x, y + 1, game->tiles[y][x]))
		{
			if (game->game_end)
				return (0);
			game->tiles[y][x].type = '0';
		}
		else
		{
			game->tiles[y][x].isup_or_left = 1;
			ft_mine_move(game, x, y);
		}
	}
	return (1);
}

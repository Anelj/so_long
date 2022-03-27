/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:32 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:33 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*void	*ft_mine_sprite(t_game *game)
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

int ft_ismine_moved(t_game *game, int x, int y, t_tile tile)
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
}*/

/*int ft_mine_move_left(t_game *game, int x, int y)
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
		*//*if (ft_ismine_moved(game, x - 1, y, game->tiles[y][x]))
		{
			if (game->game_end)
				return (0);
			game->tiles[y][x].type = '0';
		}
		else
		{
			game->tiles[y][x].isup_or_left = 0;
			ft_mine_moveg(game, x, y);
		}*//*
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
}*/

/*void	ft_setfreezed_mine(t_game *game, int x, int y)
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
	&& game->tiles[y - 1][x].type != '0' && game->tiles[y + 1][x].type != '0'
	&& game->tiles[y][x - 1].type != 'P' && game->tiles[y][x + 1].type != 'P'
	   && game->tiles[y - 1][x].type != 'P' && game->tiles[y + 1][x].type !=
	   'P')
	{
		game->tiles[y][x].isv = -1;
	}
}*/

/*int	ft_mine_moveup(t_game *game, int x, int y)
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
		*//*if (ft_ismine_moved(game, x, y - 1, game->tiles[y][x]))
		{
			if (game->game_end)
				return (0);
			game->tiles[y][x].type = '0';
		}
		else
		{
			game->tiles[y][x].isup_or_left = 0;
			ft_mine_move(game, x, y);
		}*//*
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
}*/

/*int	ft_mine_move(t_game *game, int x, int y)
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
		*//*if (game->tiles[y][x].isup_or_left)
		{
			if (ft_ismine_moved(game, x, y - 1, game->tiles[y][x]))
			{
				if (game->game_end)
					return (0);
				game->tiles[y][x].type = '0';
			}
			else
			{
				game->tiles[y][x].isup_or_left = 0;
				ft_mine_move(game, x, y);
			}
		} else
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
		}*//*
	}
	else if (game->tiles[y][x].isv == 0)
		return (ft_mine_moveg(game, x, y));
	return (1);
}*/

static void	*ft_getimg_toput(t_game *game, t_tile **tiles, int x, int y)
{
	void	*img;

	img = NULL;
	if (tiles[y][x].type == '1')
		img = game->img_wall;
	else if (tiles[y][x].type == '0')
		img = game->img_empty;
	else if (tiles[y][x].type == 'E')
		img = game->img_exit;
	else if (tiles[y][x].type == 'P')
		img = game->player.curimg;
	else if (tiles[y][x].type == 'C')
		img = game->img_collectable;
	else if (tiles[y][x].type == 'M')
	{
		img = ft_mine_sprite(game);
		if (!game->game_end)
		{
			ft_mine_move(game, x, y);
		}
	}
	return (img);
}

void	ft_update_helper(t_game *game, t_tile **tiles, int x, int y)
{
	void	*img;

	if (game->mine.frame == 1)
		game->mine.frame = 2;
	else
		game->mine.frame = 1;
	while (y < game->hightpx / 64)
	{
		x = 0;
		while (x < game->widthpx / 64)
		{
			img = ft_getimg_toput(game, tiles, x, y);
			mlx_put_image_to_window(
				game->mlx, game->window, img, tiles[y][x].x, tiles[y][x].y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->panel.ref, 0,
		game->hightpx);
	mlx_string_put(game->mlx, game->window, 1, game->hightpx + 20, 0x000000,
		game->moves_num);
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
	if (game->game_end == 2)
		return (0);
	else if (game->game_end)
		game->game_end = 2;
	ft_update_helper(game, tiles, x, y);
	if (game->game_end && !game->won)
		mlx_put_image_to_window(
			game->mlx, game->window, game->game_lost, game->widthpx / 2 - 96,
			game->hightpx / 2 - 32);
	else if (game->game_end && game->won)
		mlx_put_image_to_window(
			game->mlx, game->window, game->game_ok, game->widthpx / 2 - 96,
			game->hightpx / 2 - 32);
	return (0);
}

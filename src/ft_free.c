/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:17:48 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:17:50 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tiles(t_tile **tiles)
{
	int	i;

	i = 0;
	while (tiles[i])
	{
		free(tiles[i]);
		i++;
	}
	free(tiles);
}

void	ft_error_after_secondread(
		int i, int line_count, char **map, t_game *game)
{
	if (i != line_count)
	{
		while (i > 0)
		{
			free(map[--i]);
		}
		free(map);
		ft_error_and_exit("File is empty or it can not be read.\n", game);
	}
}

void	ft_error_and_exit(char *string, t_game *game)
{
	free(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(string, 2);
	exit(1);
}

void	ft_free_trying_tofill_tiles(t_game *game, char **map, char *error)
{
	ft_free_map(map);
	ft_free_tiles(game->tiles);
	ft_error_and_exit(error, game);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

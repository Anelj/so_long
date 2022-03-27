/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:53 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:19:54 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_linecount_and_exit(t_game *game, int line_count)
{
	if (!line_count)
		ft_error_and_exit("File is empty or it can not be read.\n", game);
	if (line_count == 1 || line_count == 2)
		ft_error_and_exit("Map is too small.\n", game);
}

void	ft_show_moves_free(t_game *game, char *s)
{
	ft_destroy_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(1);
}

int	ft_close(t_game *game)
{
	ft_destroy_game(game);
	exit(0);
}

void	ft_destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.img1);
	mlx_destroy_image(game->mlx, game->player.img2);
	mlx_destroy_image(game->mlx, game->img_empty);
	mlx_destroy_image(game->mlx, game->img_collectable);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->mine.img1);
	mlx_destroy_image(game->mlx, game->mine.img2);
	mlx_destroy_image(game->mlx, game->game_lost);
	mlx_destroy_image(game->mlx, game->game_ok);
	mlx_destroy_image(game->mlx, game->panel.ref);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	ft_free_tiles(game->tiles);
	free(game->moves_num);
	free(game);
}

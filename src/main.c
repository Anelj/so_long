/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:03 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:19:05 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_files_to_images(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 0;
	img_y = 0;
	game->img_collectable = mlx_xpm_file_to_image(
			game->mlx, "./images/collectable.xpm", &img_x, &img_y);
	game->img_empty = mlx_xpm_file_to_image(
			game->mlx, "./images/empty.xpm", &img_x, &img_y);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, "./images/exit.xpm", &img_x, &img_y);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, "./images/player.xpm", &img_x, &img_y);
	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, "./images/wall.xpm", &img_x, &img_y);
}

static t_game	*ft_create_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_error_and_exit("Can not allocate memory in main for game.\n", game);
	}
	game->moves = 0;
	game->collectibles = 0;
	game->players = 0;
	game->exits = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_game		*game;

	if (argc < 2)
		return (0);
	game = ft_create_game();
	map = ft_read_map(*(argv + 1), game);
	ft_create_tiles_from_map(map, game);
	ft_free_map(map);
	game->mlx = mlx_init();
	game->window = mlx_new_window(
			game->mlx, game->widthpx, game->hightpx, "so long");
	mlx_hook(game->window, 17, 0, ft_close, game);
	ft_files_to_images(game);
	mlx_key_hook(game->window, ft_player_move, (void *)game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
	return (0);
}

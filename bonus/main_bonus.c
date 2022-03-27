/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:56 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:57 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*void ft_files_to_mine_img1(t_game *game)
{
	game->mine = malloc(sizeof(t_mine));
	if (game->mine)
		game->mine->next = malloc(sizeof(t_mine));
	if (game->mine == NULL || game->mine->next == NULL)
	{
		ft_destroy_game(game);
		exit(1);
	}
	game->mine->next->next = game->mine;
	game->mine->img = mlx_xpm_file_to_image(
			game->mlx, "./images/enemy.xpm", &img_x, &img_y);
	game->mine->next->img = mlx_xpm_file_to_image(
			game->mlx, "./images/enemy1.xpm", &img_x, &img_y);
}*/
void	ft_files_to_mine_img(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 0;
	img_y = 0;
	game->mine.img1 = mlx_xpm_file_to_image(
			game->mlx, "./images/enemy.xpm", &img_x, &img_y);
	game->mine.img2 = mlx_xpm_file_to_image(
			game->mlx, "./images/enemy1.xpm", &img_x, &img_y);
	game->mine.frame = 1;
}

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
	game->player.img1 = mlx_xpm_file_to_image(
			game->mlx, "./images/player.xpm", &img_x, &img_y);
	game->player.img2 = mlx_xpm_file_to_image(
			game->mlx, "./images/player_right.xpm", &img_x, &img_y);
	game->player.curimg = game->player.img2;
	game->player.lr = 2;
	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, "./images/wall.xpm", &img_x, &img_y);
	game->game_lost = mlx_xpm_file_to_image(
			game->mlx, "./images/game_lost.xpm", &img_x, &img_y);
	game->game_ok = mlx_xpm_file_to_image(
			game->mlx, "./images/game_ok.xpm", &img_x, &img_y);
	ft_files_to_mine_img(game);
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
	game->mine = (t_mine){0};
	game->mine.freeze = 100;
	game->game_end = 0;
	game->moves_num = ft_strdup("Moves : 0");
	if (!(game->moves_num))
	{
		ft_error_and_exit("Can not allocate memory for moves_num.\n", game);
	}
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
			game->mlx, game->widthpx, game->hightpx + 32, "so long");
	mlx_hook(game->window, 17, 0, ft_close, game);
	ft_files_to_images(game);
	ft_create_and_set_panel(game, ft_create_color(35, 136, 197, 0));
	mlx_key_hook(game->window, ft_player_move, (void *)game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
	return (0);
}

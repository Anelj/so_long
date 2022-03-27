/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:17 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:18 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_shell_moves(int (*f)(t_game *), t_game *game)
{
	char	*num;
	char	*moves_num;

	moves_num = NULL;
	if ((*f)(game))
	{
		write(1, "Moves : ", 8);
		ft_putnbr_fd(++(game->moves), 1);
		ft_putchar_fd('\n', 1);
		num = ft_itoa(game->moves);
		if (!num)
		{
			ft_show_moves_free(game, "Can not allocate memory for num.\n");
		}
		else
			moves_num = ft_strjoin("Moves : ", num);
		free(num);
		if (!moves_num)
		{
			ft_show_moves_free(
				game, "Can not allocate memory for moves_num.\n");
		}
		free(game->moves_num);
		game->moves_num = moves_num;
	}
}

int	ft_player_move(int key, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	if (key == 53)
	{
		ft_destroy_game(game);
		exit(0);
	}
	if (game->game_end)
		return (1);
	if (key == 13)
		ft_print_shell_moves(ft_move_player_up, game);
	else if (key == 2)
		ft_print_shell_moves(ft_move_player_right, game);
	else if (key == 0)
		ft_print_shell_moves(ft_move_player_left, game);
	else if (key == 1)
		ft_print_shell_moves(ft_move_player_down, game);
	return (1);
}

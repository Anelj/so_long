/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:18:23 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:18:24 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_shell_moves(int (*f)(t_game *), t_game *game)
{
	if ((*f)(game))
	{
		write(1, "Moves : ", 8);
		ft_putnbr_fd(++(game->moves), 1);
		ft_putchar_fd('\n', 1);
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

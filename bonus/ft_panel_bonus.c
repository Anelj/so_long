/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panel_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:20:22 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:20:23 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_color	ft_create_color(int r, int g, int b, int t)
{
	t_color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.t = t;
	return (result);
}

static t_panel	ft_init_panel(t_game *game)
{
	t_panel	result;

	result.width = game->widthpx;
	result.hight = 32;
	result.line_size = 0;
	result.bit_per_px = 0;
	result.end = 0;
	result.ref = mlx_new_image(game->mlx, game->widthpx, 32);
	return (result);
}

void	ft_create_and_set_panel(t_game *game, t_color color)
{
	t_panel	panel;
	char	*addr;
	int		x;
	int		y;

	panel = ft_init_panel(game);
	addr = mlx_get_data_addr(panel.ref, &(panel.bit_per_px),
			&(panel.line_size), &(panel.end));
	y = 0;
	while (y < panel.hight)
	{
		x = 0;
		while (x < panel.width)
		{
			addr[4 * x + panel.line_size * y + 0] = color.r;
			addr[4 * x + panel.line_size * y + 1] = color.g;
			addr[4 * x + panel.line_size * y + 2] = color.b;
			addr[4 * x + panel.line_size * y + 3] = color.t;
			x++;
		}
		y++;
	}
	game->panel = panel;
	mlx_put_image_to_window(game->mlx, game->window, game->panel.ref, 0,
		game->hightpx);
}

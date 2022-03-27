/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:19:11 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/24 22:19:12 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct s_tile
{
	char	type;
	int		x;
	int		y;
}	t_tile;

typedef struct s_player
{
	t_tile	tile;
}	t_player;

typedef struct s_panel
{
	void	*ref;
	int		width;
	int		hight;
	int		bit_per_px;
	int		line_size;
	int		end;
}	t_panel;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_tile		**tiles;
	t_player	player;
	t_panel		panel;
	int			widthpx;
	int			hightpx;
	int			moves;
	int			collectibles;
	int			players;
	int			exits;
	void		*img_wall;
	void		*img_empty;
	void		*img_player;
	void		*img_collectable;
	void		*img_exit;
}	t_game;

void	ft_destroy_game(t_game *game);
int		ft_player_move(int key, void *g);
int		ft_move_player_down(t_game *game);
int		ft_move_player_left(t_game *game);
int		ft_move_player_right(t_game *game);
int		ft_move_player_up(t_game *game);
void	ft_free_trying_tofill_tiles(t_game *game, char **map, char *error);
int		ft_update(void *g);
int		ft_close(t_game *game);
void	ft_free_map(char **map);
void	ft_free_tiles(t_tile **tiles);
void	ft_error_after_secondread(
			int i, int line_count, char **map, t_game *game);
void	ft_error_and_exit(char *string, t_game *game);
int		ft_close(t_game *game);
char	**ft_read_map(char *path, t_game *game);
t_tile	**ft_create_tiles_from_map(char **map, t_game *game);
char	*get_next_line(int fd);
int		ft_check_type(char **map, int y, int x, t_game *game);
int		ft_check_ifallelements_avail(t_game *game, char **map);
void	ft_check_mappath(char *path, t_game *game);
void	ft_check_mapwidth(int fd, char *s, size_t width, t_game *game);
void	ft_check_linecount_and_exit(t_game *game, int linecount);

#endif

NAME = so_long
DIR_OBJ = obj
SRC = main.c get_next_line.c get_next_line_utils.c ft_move_player.c ft_update.c ft_check.c ft_free.c ft_free1.c\
ft_move_options.c ft_read_map.c ft_create_tiles.c
SRCM = $(addprefix src/, $(SRC))
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
SRCB_TMP = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_move_player_bonus.c ft_update_bonus.c\
ft_check_bonus.c ft_free_bonus.c ft_free1_bonus.c ft_move_options_bonus.c ft_read_map_bonus.c ft_create_tiles_bonus.c\
ft_panel_bonus.c ft_mine_bonus.c ft_mine1_bonus.c
SRCB = $(addprefix bonus/, $(SRCB_TMP))
OBJB = $(addprefix $(DIR_OBJ)/, $(SRCB_TMP:.c=.o))
FLAGS = -Wall -Wextra -Werror -g -Iminilibx_opengl -Ilibft
LINKS = -I/usr/include -Ilibft -Iminilibx_opengl -L./minilibx_opengl -lmlx -L./libft -lft -framework OpenGL -framework AppKit
#LINKS = -I/usr/include -L/usr/lib -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit -Iminilibx_opengl -L./libft -lft -lX11
#LINKS = -I/usr/include -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit -Iminilibx_opengl -L./libft -lft
#LINKS = -I/usr/include -Iminilibx_linux -L./minilibx-linux -lmlx_Linux -L/usr/lib -L./libft -lft -lXext -lX11 -lm -lz
all: $(NAME)

$(NAME): delprogr ./libft/libft.a ./minilibx_opengl/libmlx.a $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

$(DIR_OBJ)/%.o : ./src/%.c ./src/so_long.h
	mkdir -p $(DIR_OBJ)
	gcc $(FLAGS) -c $< -o $@

./libft/libft.a : libft;

libft :
	$(MAKE) bonus -C ./libft

./minilibx_opengl/libmlx.a : minilibx;

minilibx :
	$(MAKE) -C ./minilibx_opengl

bonus: delprogr ./libft/libft.a ./minilibx_opengl/libmlx.a $(OBJB)
	gcc $(FLAGS) $(OBJB) $(LINKS) -o $(NAME)

$(DIR_OBJ)/%.o : ./bonus/%.c ./bonus/so_long_bonus.h
	mkdir -p $(DIR_OBJ)
	gcc $(FLAGS) -c $< -o $@

exe: bonus
	@./$(NAME) ./maps/map_bonus4.ber

delprogr :
	rm -rf $(NAME)

clean:
	rm -rf $(DIR_OBJ)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_opengl

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : fclean all delprogr re clean bonus libft minilibx

NAME = fdf

ifeq ($(uname -s),Darwin)
	MLX_DIR = minilibx_macos
	MLX = libmlx.a
	GETLIB = wget https://projects.intra.42.fr/uploads/document/document/7120/minilibx_macos_sierra_20161017.tgz && tar -xf
	MLX_FLAGS = -g -L -l mlx -framework OpenGL -framework AppKit -lm
else
	MLX_DIR = minilibx-linux
	GETLIB = git clone https://github.com/42Paris/minilibx-linux.git
	MLX = libmlx_Linux.a
	MLX_FLAGS = -lXext -lX11 -lm
endif

CC = cc
MAPS = wget https://projects.intra.42.fr/uploads/document/document/7118/maps.zip
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/libft.a $(MLX_DIR)/$(MLX) include/fdf.h $(MLX_DIR)/mlx.h
SRC = src/*.c

all:
	@echo "Download Lib minilibx for $(uname -s)"
	$(GETLIB)
	$(MAPS)
	@unzip maps.zip
	@rm -rf maps.zip __MACOSX
	@make -C libft/ all
	@make -C $(MLX_DIR) all
	$(CC) $(FLAGS) $(SRC) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(MLX_DIR) test_maps

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all


.PHONY: all clean fclean re
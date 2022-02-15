NAME = fdf
DEFAULTOS := "GNU/Linux"
GETOS := $(shell uname -s)
ifeq ($(GETOS), Linux)
	MLX_DIR = minilibx-linux
	DEFINE = include/init_mlx/linux/define.h
	KEYSET = key_map/key_linux/key.c
	GETLIB = git clone https://github.com/42Paris/minilibx-linux.git
	MAPS = wget https://projects.intra.42.fr/uploads/document/document/7118/maps.zip
	MLX = libmlx_Linux.a
	MLX_FLAGS = -lXext -lX11 -lm
else
	MLX_DIR = minilibx_macos
	MLX = libmlx.a
	DEFINE = include/init_mlx/macos/define.h
	KEYSET = key_map/key_mac/key.c
	GETLIB = curl -O https://projects.intra.42.fr/uploads/document/document/7120/minilibx_macos_sierra_20161017.tgz && tar -xf minilibx_macos_sierra_20161017.tgz
	MAPS = curl -O https://projects.intra.42.fr/uploads/document/document/7118/maps.zip
	MLX_FLAGS = -g -L -l mlx -framework OpenGL -framework AppKit -lm
endif

CC = cc
GETLIBFT = git clone https://github.com/MidzakiKayo/libft.git
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/libft.a $(DEFINE) $(MLX_DIR)/$(MLX) include/fdf.h $(MLX_DIR)/mlx.h $(KEYSET)
SRC = src/*.c

all:
	@echo "Download LIBFT from git"
	$(GETLIBFT)
	@echo "Download Lib minilibx for $(GETOS)"
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
	

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@rm -rf $(MLX_DIR) test_maps libft

re: fclean all


.PHONY: all clean fclean re

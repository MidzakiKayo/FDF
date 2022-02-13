NAME = fdf

ifeq ($(uname -s),Darwin)
	MLX_DIR = minilibx_macos/
	MLX = libmlx.a
	MLX_FLAGS = -g -L -l mlx -framework OpenGL -framework AppKit -lm
else
	MLX_DIR = mlx_linux
	MLX = libmlx_Linux.a
	MLX_FLAGS = -lXext -lX11 -lm
endif


CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/libft.a $(MLX_DIR)/$(MLX) include/fdf.h $(MLX_DIR)/mlx.h
SRC = src/*.c

all:
	@make -C libft/ all
	@make -C $(MLX_DIR) all
	$(CC) $(FLAGS) $(SRC) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C $(MLX_DIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all


.PHONY: all clean fclean re
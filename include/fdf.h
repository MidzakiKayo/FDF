/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:39:02 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/02 16:39:02 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

#define MAX(a, b) (a > b ? a : b)

//COLOR
# define WHITE	0xFFFAFA
# define RED 	0xfe0009
# define GREEN 	0x10ff01
# define BLUE 	0x2300ff

#ifdef __APPLE__
# include "../minilibx_macos/mlx.h"
# define KEYUP 			126
# define KEYLEFT 		123
# define KEYRIGHT 		124
# define KEYDOWN 		125
# define KEYPGUP 		116
# define KEYPGDOWN 		121
# define KEYPUSHUP		18
# define KEYPUSHDOWN	19
# define KEYPLUS 		24
# define KEYMINUS 		27
# define KEYORTO		31
# define KEYESC 		53
# define KEYDEFAULT 	34
# define KEYCOLOR		8
#endif

#ifdef __linux__
# include "../minilibx-linux/mlx.h"
# define KEYUP			65362
# define KEYLEFT		65361
# define KEYRIGHT		65363
# define KEYDOWN		65364
# define KEYPGUP		65365
# define KEYPGDOWN		65366
# define KEYPUSHUP		49
# define KEYPUSHDOWN	50
# define KEYPLUS		61
# define KEYMINUS		45
# define KEYORTO		111
# define KEYESC			65307
# define KEYDEFAULT		105
# define KEYCOLOR		99
#endif


typedef struct
{
	int		width;
	int 	height;
	int 	**z_matrix;
	int 	zoom;
	int 	color;
	int		setcolor;
	int 	screen_height;
	int 	screen_width;
	int 	izometric;
	int 	max;
	int 	push;
	int		x_i;
	int		y_i;
	int 	z;
	int 	z1;

	float 	angle;
	float 	x_step;
	float 	y_step;
	float 	x;
	float 	y;
	float 	x1;
	float 	y1;

	void 	*mlx_ptr;
	void 	*win_ptr;
} fdf;

//error list
void	ft_error_fd();
void	error_argc();
void	error_extension_map();
void	error_alloc();
//control
int		deal_key(int key, fdf *data);
void	exit_init(fdf *data);
void	change_color(fdf *data);
void	reset_position(fdf *data);
void	convert_to_2d(fdf *data);
void    rotate(int key, fdf *data);
void    move(int key, fdf *data);
//print_menu
void	print_menu(fdf *param);
void	collor(fdf *data);
//init_tab
void    tab_init(fdf *data, char *filename);
//main
int		main(int argc, char **argv);
int		ft_len(char *str);
void    check_arg(int argc);
//draw
void	recive_cord1(fdf *data);
void	recive_cord2(fdf *data, int plusx, int plusy);
void	set_zoom(fdf *data);
void	set_size(fdf *data);
void	draw(fdf *data);
void	draw_map(fdf *data);
//readmap
void	readmap(fdf *data, char *file);

#endif
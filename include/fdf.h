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

# include "./init_mlx/linux/define.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct t_keys
{
	int	keyup;
	int	keyleft;
	int	keyright;
	int	keydown;
	int	keypgup;
	int	keypgdown;
	int	keypushup;
	int	keypushdown;
	int	keyplus;
	int	keyminus;
	int	keyorto;
	int	keyesc;
	int	keydefault;
	int	keycolor;
}	t_key;

typedef struct t_param
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		setcolor;
	int		screen_height;
	int		screen_width;
	int		izometric;
	int		max;
	int		push;
	int		x_i;
	int		y_i;
	int		z;
	int		z1;
	float	angle;
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	float	x1;
	float	y1;

	void	*mlx_ptr;
	void	*win_ptr;
	t_key		init;
}	t_fdf;

void	key_init(t_fdf *data);
int		max(int a, int b);
void	ft_error_fd(void);
void	error_argc(void);
void	error_extension_map(void);
void	error_alloc(void);
int		deal_key(int key, t_fdf *data);
void	exit_init(t_fdf *data);
void	change_color(t_fdf *data);
void	reset_position(t_fdf *data);
void	convert_to_2d(t_fdf *data);
void	rotate(int key, t_fdf *data);
void	move(int key, t_fdf *data);
void	print_menu(t_fdf *param);
void	collor(t_fdf *data);
void	tab_init(t_fdf *data, char *filename);
int		main(int argc, char **argv);
int		ft_len(char *str);
void	check_arg(int argc);
void	recive_cord1(t_fdf *data);
void	recive_cord2(t_fdf *data, int plusx, int plusy);
void	set_zoom(t_fdf *data);
void	set_size(t_fdf *data);
void	draw(t_fdf *data);
void	draw_map(t_fdf *data);
void	readmap(t_fdf *data, char *file);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 04:49:42 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/04 04:49:42 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	module(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(t_fdf *data)
{
	data->x = (data->x - data->y) * cos(data->angle);
	data->y = (data->x + data->y) * sin(data->angle) - data->z;
	data->x1 = (data->x1 - data->y1) * cos(data->angle);
	data->y1 = (data->x1 + data->y1) * sin(data->angle) - data->z1;
}

void	get_z(t_fdf *data)
{
	if (!(data->z_matrix[(int)data->y][(int)data->x]))
		data->z = data->z_matrix[(int)data->y][(int)data->x];
	else
		data->z = data->z_matrix[(int)data->y][(int)data->x] + data->push;
	if (!(data->z_matrix[(int)data->y1][(int)data->x1]))
		data->z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	else
		data->z1 = data->z_matrix[(int)data->y1][(int)data->x1] + data->push;
}

void	draw(t_fdf *data)
{
	get_z(data);
	set_zoom(data);
	collor(data);
	if (data->izometric)
		isometric(data);
	set_size(data);
	data->x_step = data->x1 - data->x;
	data->y_step = data->y1 - data->y;
	data->max = max(module(data->x_step), module(data->y_step));
	data->x_step /= data->max;
	data->y_step /= data->max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			data->x, data->y, data->color);
		data->x += data->x_step;
		data->y += data->y_step;
	}
}

void	draw_map(t_fdf *data)
{
	print_menu(data);
	data->y_i = 0;
	while (data->y_i < data->height)
	{
		data->x_i = 0;
		while (data->x_i < data->width)
		{
			if (data->x_i < data->width - 1)
			{
				recive_cord1(data);
				recive_cord2(data, 1, 0);
				draw(data);
			}
			if (data->y_i < data->height - 1)
			{
				recive_cord1(data);
				recive_cord2(data, 0, 1);
				draw(data);
			}
			data->x_i++;
		}
		data->y_i++;
	}
}

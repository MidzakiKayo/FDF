/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:20:20 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 13:20:20 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	tab_init(t_fdf *data, char *filename)
{
	data->height = 0;
	data->width = 0;
	data->zoom = 15;
	data->color = 0;
	data->setcolor = 1;
	data->screen_height = 1000;
	data->screen_width = 1000;
	data->izometric = 1;
	data->max = 0;
	data->x_i = 0;
	data->y_i = 0;
	data->push = 0;
	data->z = 0;
	data->z1 = 0;
	data->x_step = 0.0;
	data->y_step = 0.0;
	data->angle = 0.8;
	data->z_matrix = NULL;
	readmap(data, filename);
	key_init(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_width,
			data->screen_height, "FdF - by Bchytter");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:21:50 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 13:21:50 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	convert_to_2d(fdf *data)
{
	if (data->izometric)
		data->izometric = 0;
	else
		data->izometric = 1;
}

void	reset_position(fdf *data)
{
	data->angle = 0.8;
	data->screen_height = 1000;
	data->screen_width = 1000;
	data->setcolor = 1;
	data->izometric = 1;
	data->zoom = 15;
	data->push = 0;
}

void	change_color(fdf *data)
{
	if (data->setcolor != 3)
		data->setcolor++;
	else
		data->setcolor = 1;
}

void	exit_init(fdf *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->z_matrix[y]);
		y++;
	}
	free(data->z_matrix);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:55:43 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 13:55:43 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move(int key, t_fdf *data)
{
	if (key == data->init.keyup)
		data->screen_height -= 10;
	if (key == data->init.keydown)
		data->screen_height += 10;
	if (key == data->init.keyleft)
		data->screen_width -= 10;
	if (key == data->init.keyright)
		data->screen_width += 10;
}

void	rotate(int key, t_fdf *data)
{
	if (key == data->init.keypgup)
		data->angle -= 0.1;
	if (key == data->init.keypgdown)
		data->angle += 0.1;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == data->init.keycolor)
		change_color(data);
	if (key >= data->init.keyleft && key <= data->init.keypgdown)
		move(key, data);
	if (key == data->init.keypgup || key == data->init.keypgdown)
		rotate(key, data);
	if (key == data->init.keyminus)
		data->zoom -= 1;
	if (key == data->init.keyplus)
		data->zoom += 1;
	if (key == data->init.keydefault)
		reset_position(data);
	if (key == data->init.keypushup)
		data->push += 10;
	if (key == data->init.keypushdown)
		data->push -= 10;
	if (key == data->init.keyorto)
		convert_to_2d(data);
	if (key == data->init.keyesc)
		exit_init(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	ft_printf("%d\n", key);
	return (0);
}

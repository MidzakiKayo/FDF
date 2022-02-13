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

void	move(int key, fdf *data)
{
	if (key == KEYUP)
		data->screen_height -= 10;
	if (key == KEYDOWN)
		data->screen_height += 10;
	if (key == KEYLEFT)
		data->screen_width -= 10;
	if (key == KEYRIGHT)
		data->screen_width += 10;
}

void	rotate(int key, fdf *data)
{
	if (key == KEYPGUP)
		data->angle -= 0.1;
	if (key == KEYPGDOWN)
		data->angle += 0.1;
}

int	deal_key(int key, fdf *data)
{
	if (key == KEYCOLOR)
		change_color(data);
	if (key >= KEYLEFT && key <= KEYDOWN)
		move(key, data);
	if (key == KEYPGUP || key == KEYPGDOWN)
		rotate(key, data);
	if (key == KEYMINUS)
		data->zoom -= 1;
	if (key == KEYPLUS)
		data->zoom += 1;
	if (key == KEYDEFAULT)
		reset_position(data);
	if (key == KEYPUSHUP)
		data->push += 10;
	if (key == KEYPUSHDOWN)
		data->push -= 10;
	if (key == KEYORTO)
		convert_to_2d(data);
	if (key == KEYESC)
		exit_init(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	ft_printf("%d\n", key);
	return (0);
}

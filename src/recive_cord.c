/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recive_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:32:33 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 14:32:33 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	recive_cord1(fdf *data)
{
	data->x = data->x_i;
	data->y = data->y_i;
}

void	recive_cord2(fdf *data, int plusx, int plusy)
{
	data->x1 = data->x_i + plusx;
	data->y1 = data->y_i + plusy;
}

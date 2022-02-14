/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:05:06 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 14:05:06 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	collor(t_fdf *data)
{
	if (data->setcolor == 1)
	{
		if (data->z || data->z1)
			data->color = 0xfe0009;
		else
			data->color = 0xFFFAFA;
	}
	else if (data->setcolor == 2)
	{
		if (data->z || data->z1)
			data->color = 0x10ff01;
		else
			data->color = 0xFFFAFA;
	}
	else if (data->setcolor == 3)
	{
		if (data->z || data->z1)
			data->color = 0x2300ff;
		else
			data->color = 0xFFFAFA;
	}
}

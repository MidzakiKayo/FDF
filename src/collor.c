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

void	collor(fdf *data)
{
	if (data->setcolor == 1)
	{
		if (data->z || data->z1)
			data->color = RED;
		else
			data->color = WHITE;
	}
	else if (data->setcolor == 2)
	{
		if (data->z || data->z1)
			data->color = GREEN;
		else
			data->color = WHITE;
	}
	else if (data->setcolor == 3)
	{
		if (data->z || data->z1)
			data->color = BLUE;
		else
			data->color = WHITE;
	}
}

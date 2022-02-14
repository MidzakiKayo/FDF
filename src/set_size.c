/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:15 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 14:06:15 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	set_size(t_fdf *data)
{
	data->x += data->screen_width / 2;
	data->x1 += data->screen_width / 2;
	data->y += data->screen_height / 2;
	data->y1 += data->screen_height / 2;
}

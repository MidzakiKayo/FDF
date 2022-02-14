/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:20:39 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/14 16:20:39 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	key_init(t_fdf *data)
{
	data->init.keyup = 65362;
	data->init.keyleft = 65361;
	data->init.keyright = 65363;
	data->init.keydown = 65364;
	data->init.keypgup = 65365;
	data->init.keypgdown = 65366;
	data->init.keypushup = 49;
	data->init.keypushdown = 50;
	data->init.keyplus = 61;
	data->init.keyminus = 45;
	data->init.keyorto = 111;
	data->init.keyesc = 65307;
	data->init.keydefault = 105;
	data->init.keycolor = 99;
}

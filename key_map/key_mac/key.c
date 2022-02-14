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
	data->init.keyup = 126;
	data->init.keyleft = 123;
	data->init.keyright = 124;
	data->init.keydown = 125;
	data->init.keypgup = 116;
	data->init.keypgdown = 121;
	data->init.keypushup = 18;
	data->init.keypushdown = 19;
	data->init.keyplus = 24;
	data->init.keyminus = 27;
	data->init.keyorto = 31;
	data->init.keyesc = 53;
	data->init.keydefault = 34;
	data->init.keycolor = 8;
}

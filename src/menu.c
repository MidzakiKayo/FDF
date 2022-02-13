/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:19:23 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 13:19:23 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_menu(fdf *param)
{
	char	*menu;

	menu = "Move picture arrow: Up, Down, Left, Right";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 15, 0x03fc35, menu);
	menu = "For ZOOM press: +/-";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 30, 0x03fc35, menu);
	menu = "For izometric rotation: PgUP/PgDown";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 45, 0x03fc35, menu);
	menu = "For ortographic viwe press: O";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 60, 0x03fc35, menu);
	menu = "For return default position press: I";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 75, 0x03fc35, menu);
	menu = "Change color press: C";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 90, 0x03fc35, menu);
	menu = "For exit press: ESC";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 14, 105, 0x03fc35, menu);
}

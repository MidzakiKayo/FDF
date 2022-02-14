/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 04:54:21 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 04:54:21 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	check_arg(int argc)
{
	if (argc != 2)
		error_argc();
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	check_arg(argc);
	tab_init(data, argv[1]);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
